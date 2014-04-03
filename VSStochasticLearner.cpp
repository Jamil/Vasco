//
//  VSStochasticLearner.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 3/20/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSStochasticLearner.h"

#define STOCHASTIC_TOLERANCE 0.00001

#pragma mark - Constructor

VSStochasticLearner::VSStochasticLearner(int numParams, vector<VSData> *data, float learningRate) : VSLearner(numParams, data, learningRate) {
    // No specific initialization needed for derived class
}

#pragma mark - Hypothesis

double VSStochasticLearner::getHypothesisForData(const VSData &data) {
    // LOGISTIC REGRESSION
    // h_{\theta}(x) = \frac{1}{1+e^{-\theta^{T}x}}
    
    double hyp = 0;
    for (int i = 0; i < _M; i++) {
        hyp += data.features()[i] * _parameterValues[i];
    }
    
    hyp = 1 + exp(-1 * hyp); // Denominator
    hyp = 1/hyp;
    
    return hyp;
}

#pragma mark - Update Rule

void VSStochasticLearner::step_stochastic(int i, int j, float target) {
    // Where i is the parameter to update, j is the training example
    // Fixed learning rate for now, but may change that later depending on performance
    
    float hypothesis = getHypothesisForData(_data->at(j));
    float xi = _data->at(j).features()[i];
    
    _parameterValues[i] += _learningRate * (target - hypothesis) * xi;
}

void VSStochasticLearner::update(float target) {
    updateUntilConvergence(target);
}

void VSStochasticLearner::updateUntilConvergence(float target) {
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
                    step_stochastic(i, j, target);
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
