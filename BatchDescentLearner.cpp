//
//  BatchDescentLearner.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 3/20/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "BatchDescentLearner.h"

#define BATCH_TOLERANCE 0.001

#pragma mark - Constructor

BatchDescentLearner::BatchDescentLearner(int numParams, vector<VSSupervisedData*> data, float learningRate) : VSLearner(numParams, data, learningRate) {
}


BatchDescentLearner::BatchDescentLearner(int numParams, vector<VSSupervisedData*> data, float learningRate, float (*hypothesis)(float y)) : VSLearner(numParams, data, learningRate, hypothesis) {
}

void BatchDescentLearner::update() {
  updateUntilConvergence();
}

#pragma mark - Hypothesis

double BatchDescentLearner::getHypothesisForData(VSData* data) {
  // LMS REGRESSION
  // h_{\theta}(x) = \theta^{T}x

  double hyp = 0;
  for (int i = 0; i < _M; i++) {
    hyp += data->features()[i] * _parameterValues[i];
  }

  if (_hypothesis) 
    hyp = _hypothesis(hyp);

  return hyp;
}

#pragma mark - Update Rule

void BatchDescentLearner::updateUntilConvergence() {
  float error = 0;

  int j_max = _data.size();

  while (fabs(error) < BATCH_TOLERANCE) {
    // for each parameter 
    for (int j = 0; j < j_max; j++) {
      // for each training example 
      float sum_err = 0;
      for (int i = 0; i < _M; i++) {
        float hyp = getHypothesisForData(_data.at(j));
        float actual = _data.at(j)->supervisedValue();
        sum_err += actual - hyp;
      }
      float update_size = sum_err * _learningRate;

      // update 
      _parameterValues[j] += update_size;
      error = update_size;
      LOG("Update size: %f, New Value: %f\n", update_size, _parameterValues[j]);
    } 
  }
}
