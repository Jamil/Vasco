//
//  VSLearner.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSLearner.h"

#define STOCHASTIC_TOLERANCE 0.00001

#pragma mark - Constructor and Destructor

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


#pragma mark - Public Functions

int VSLearner::numParams() {
    return _M;
}
