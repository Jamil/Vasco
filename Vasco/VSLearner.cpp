//
//  VSLearner.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSLearner.h"

// Set to 0 for batch gradient descent, 1 for stochastic gradient descent
#define STOCHASTIC 1
#define STOCHASTIC_TOLERANCE 0.00001
#define BATCH_TOLERANCE 0.5

#ifdef PRINT_LOG
#define LOG(string, ...) printf(string, __VA_ARGS__)
#else
#define LOG(string, ...)
#endif

#pragma mark Constructor and Destructor

VSLearner::VSLearner(vector<const char*> &parameters, vector<VSData> *data, float learningRate, int IDENT) {
    /* You can initialize a VSLearner with no data, but you should pass an empty vector rather than NULL. The training examples should be stored OUTSIDE of the class. */
    
    _parameterNames = parameters;
    _learningRate = learningRate;
    _data = data;
    _IDENT = IDENT;
    
    // Initialize theta values (parameters) to the zero vector
    _M = (int)parameters.size();
    _parameterValues = (double*)malloc(sizeof(double) * _M);
    for (int i = 0; i < _M; i++)
        _parameterValues[i] = 0;
}

VSLearner::~VSLearner() {
    delete _data;
    delete _parameterValues;
    for (int i = 0; i < _parameterNames.size(); i++) {
        delete _parameterNames[i];
    }
}

#pragma mark – Hypothesis

double VSLearner::getHypothesisForData(const VSData &data) {
    // h_{\theta}(x) = \theta^{T}x
    
    double hyp = 0;
    for (int i = 0; i < _M; i++) {
        hyp += data.features()[i] * _parameterValues[i];
    }
    return hyp;
}

#pragma mark - Stochastic Gradient Descent

double VSLearner::step_stochastic(int i, int j) {
    // Where i is the parameter to update, j is the training example
    // Fixed learning rate for now, but may change that later depending on performance
    _parameterValues[i] += _learningRate * (_data->at(j).supervisedValues().at(_IDENT) - getHypothesisForData(_data->at(j))) * _data->at(j).features()[i];
    
    return _parameterValues[i];
}

#pragma mark - Batch Gradient Descent

double VSLearner::_sum_err_tr(int index) {
    double error = 0;
    
    // Iterate through training examples
    // ∑(y−h(x))xj
    for (int i = 0; i < _data->size(); i++) {
        error += (_data->at(i).supervisedValues().at(_IDENT) - getHypothesisForData(_data->at(i))) * _data->at(i).features()[index];
    }
    
    return error;
}

double** VSLearner::updateParameters() {
    // Perform batch gradient descent on all training examples
    // Iterate through parameters
    for (int i = 0; i < _M; i++) {
        _parameterValues[i] += _learningRate * _sum_err_tr(i);
    }
    
    return &_parameterValues;
}

#pragma mark - Public Functions

void VSLearner::updateUntilConvergence() {
    int examples = (int)_data->size();
    
    double cumulativeError = 1000; // Arbitrary really high sentinel
    double previousError = 0;
    
    if (!STOCHASTIC) {
        while (cumulativeError > BATCH_TOLERANCE) {
            previousError = cumulativeError;
            
            updateParameters();
            
            cumulativeError = 0;
            
            // Take into consideration all training examples
            for (int i = 0; i < examples; i++) {
                cumulativeError += fabs(_data->at(i).supervisedValues().at(_IDENT) - getHypothesisForData(_data->at(i)));
            }
            
            // cout << "Error: " << cumulativeError << " - previous: " << previousError << endl;
            
            assert(cumulativeError < previousError);
        }
    }
    
    else {
        
        float oldParams[_M];
        for (int i = 0; i < _M; i++)
            oldParams[i] = _parameterValues[i];
        bool nochange[_M];
        for (int i = 0; i < _M; i++)
            nochange[i] = 0;
        
        int finished = 0;
        do {
            LOG("NEW ITERATION\n", NULL);
            
            // Iterate through training set
            for (int j = 0; j < examples; j++) {
                // Update each parameter
                for (int i = 0; i < _M; i++) {
                    if (!nochange[i])
                        step_stochastic(i, j);
                }
            }
            
            // Check against old parameters
            finished = 0;
            for (int i = 0; i < _M; i++) {
                double percdiff = oldParams[i] ? fabs((_parameterValues[i] - oldParams[i])/oldParams[i]) : fabs(_parameterValues[i] - oldParams[i]);
                if (percdiff < STOCHASTIC_TOLERANCE) {
                    //cout << "Done " << i << endl;
                    nochange[i] = true;
                    finished++;
                }
                else {
                    LOG("Not done: %d\tDiff: %f%%\n", i, percdiff * 100);
                }
                oldParams[i] = _parameterValues[i];
            }
            
        } while (finished < _M);
        
    }
}

int VSLearner::numParams() {
    return _M;
}
