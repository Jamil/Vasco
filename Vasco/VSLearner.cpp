//
//  VSLearner.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSLearner.h"

// Set to 0 for batch gradient descent, 1 for stochastic gradient descent
#define STOCHASTIC_TOLERANCE 0.00001

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
    // LOGISTIC REGRESSION
    // h_{\theta}(x) = \frac{1}{1+e^{-\theta^{T}x}}
    
    double hyp = 0;
    for (int i = 0; i < _M; i++) {
        hyp += data.features()[i] * _parameterValues[i];
    }
    
    hyp = 1 + exp(-1 * hyp); // Denominator
    hyp = 1/hyp;
    
    return hyp;
    
    /*
    LMS REGRESSION
    h_{\theta}(x) = \theta^{T}x
     
        double hyp = 0;
        for (int i = 0; i < _M; i++) {
            hyp += data.features()[i] * _parameterValues[i];
        }
        return hyp;
     
     */
}

#pragma mark - Stochastic Gradient Descent

void VSLearner::step_stochastic(int i, int j) {
    // Where i is the parameter to update, j is the training example
    // Fixed learning rate for now, but may change that later depending on performance
    if (!(_data->at(j).isSupervised()))
        return;
    
    _parameterValues[i] += _learningRate * (_data->at(j).supervisedValues().at(_IDENT) - getHypothesisForData(_data->at(j))) * _data->at(j).features()[i];
}

#pragma mark - Public Functions

void VSLearner::updateUntilConvergence() {
    int examples = (int)_data->size();
    
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

int VSLearner::numParams() {
    return _M;
}
