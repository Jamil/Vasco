//
//  VSBatchDescentLearner.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 3/20/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSBatchDescentLearner.h"

#pragma mark - Constructor

VSBatchDescentLearner::VSBatchDescentLearner(int numParams, vector<VSData> *data, float learningRate) : VSLearner(numParams, data, learningRate) {
    // No specific initialization needed for derived class
}

#pragma mark - Hypothesis

double VSLearner::getHypothesisForData(const VSData &data) {
    // LMS REGRESSION
    // h_{\theta}(x) = \theta^{T}x
    
    double hyp = 0;
    for (int i = 0; i < _M; i++) {
        hyp += data.features()[i] * _parameterValues[i];
    }
    return hyp;
}
