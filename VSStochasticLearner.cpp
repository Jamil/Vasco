//
//  VSStochasticLearner.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 3/20/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSStochasticLearner.h"

#define STOCHASTIC_TOLERANCE 0.00001

void VSStochasticLearner::step_stochastic(int i, int j) {
    // Where i is the parameter to update, j is the training example
    // Fixed learning rate for now, but may change that later depending on performance
    if (!(_data->at(j).isSupervised()))
        return;
    
    _parameterValues[i] += _learningRate * (_data->at(j).supervisedValues().at(_IDENT) - getHypothesisForData(_data->at(j))) * _data->at(j).features()[i];
}

void VSStochasticLearner::update() {
    updateUntilConvergence();
}

void VSStochasticLearner::updateUntilConvergence() {
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