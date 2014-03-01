//
//  VSLearner.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSLearner.h"

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

double VSLearner::getHypothesisForData(const VSData &data) {
    // h_{\theta}(x) = \theta^{T}x
    
    double hyp = 0;
    for (int i = 0; i < _M; i++) {
        hyp += data.features()[i] * _parameterValues[i];
    }
    return hyp;
}

double VSLearner::_sum_err_tr(int index) {
    double error = 0;
    
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
        //cout << _parameterValues[i] << endl;
    }
    
    return &_parameterValues;
}

void VSLearner::updateUntilConvergence(float tolerance) {
    int examples = (int)_data->size();
    
    double cumulativeError = 10000;
    double previousError = 0;
    
    while (fabs((previousError - cumulativeError)/cumulativeError) > tolerance) {
        previousError = cumulativeError;
        
        updateParameters();
        
        cumulativeError = 0;
        for (int i = 0; i < examples; i++) {
            cumulativeError += fabs(_data->at(i).supervisedValues().at(_IDENT) - getHypothesisForData(_data->at(i)));
        }
        cout << "Cumulative Error: " << cumulativeError << endl;
    }

}

