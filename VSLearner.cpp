//
//  VSLearner.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSLearner.h"

VSLearner::VSLearner(vector<char*> &parameters, vector<VSData> *data, float learningRate) {
    /* You can initialize a VSLearner with no data, but you should pass an empty vector rather than NULL. The training examples should be stored OUTSIDE of the class. */
    
    if (!data)
        throw vs_learner_exception_no_data;
    
    _parameterNames = parameters;
    _learningRate = learningRate;
    
    // Initialize theta values (parameters) to the zero vector
    for (int i = 0; i < _parameterNames.size(); i++)
        _parameterValues.push_back(0);
}

double VSLearner::getHypothesisForData(const VSData &data) {
    // h_{\theta}(x) = \theta^{T}x
    
    int hyp = 0;
    for (int i = 0; i < data.words().size(); i++) {
        hyp += data.features().at(i) * _parameterValues.at(i);
    }
    return hyp;
}

double VSLearner::_sum_err_tr(int index) {
    double error = 0;
    for (int i = 0; i < _data->size(); i++) {
        // θj:=θj+(y−h(x))xj
        error += _data->at(i).features().at(index) + getHypothesisForData(_data->at(i));
    }
    return error;
}

vector<float>* VSLearner::updateParameters() {
    // Perform batch gradient descent on all training examples
    
    // Iterate through parameters
    for (int i = 0; i < _parameterValues.size(); i++) {
        _parameterValues.at(i) += _learningRate *
    }
    
    return &_parameterValues;
}

