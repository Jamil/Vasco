//
//  VSLearner.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSLearner.h"

// Set to 0 for batch gradient descent, 1 for stochastic
#define STOCHASTIC 0

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

void VSLearner::updateUntilConvergence(float tolerance) {
    int examples = (int)_data->size();
    
    double cumulativeError = INT_MAX; // Arbitrary really high sentinel
    double previousError = 0;
    
    
    if (!STOCHASTIC) {
        while (cumulativeError > tolerance) {
            previousError = cumulativeError;
            
            cumulativeError = 0;
            
            // Take into consideration all training examples
            for (int i = 0; i < examples; i++) {
                cumulativeError += fabs(_data->at(i).supervisedValues().at(_IDENT) - getHypothesisForData(_data->at(i)));
            }
            
            assert(cumulativeError < previousError);
        }
    }
    
    else {
        for (int i = 0; i < _M; i++) {
            double prevTheta = _parameterValues[i];
            for (int j = 0; j < examples; i++) {
                double newTheta = step_stochastic(i, j);
                
                // Check if converged
                if (fabs(newTheta - prevTheta) < tolerance)
                    return;
                
                prevTheta = newTheta;
            }
        }
    }
}

int VSLearner::numParams() {
    return _M;
}
