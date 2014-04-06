
#include "VSLearner.h"

#define STOCHASTIC_TOLERANCE 0.00001

#pragma mark - Constructor and Destructor

VSLearner::VSLearner(int numParams, vector<VSSupervisedData*> data, float learningRate) {
    /* You can initialize a VSLearner with no data, but you should pass an empty vector rather than NULL. The training examples should be stored OUTSIDE of the class. */
    
    _learningRate = learningRate;
    _data = data;
    
    // Initialize x_{i} values to the zero vector
    _M = numParams;
    _parameterValues = (double*)malloc(sizeof(double) * _M);
    for (int i = 0; i < _M; i++)
        _parameterValues[i] = 0;
}

VSLearner::~VSLearner() {
    delete _parameterValues;
}

#pragma mark - Public Functions

int VSLearner::numParams() {
    return _M;
}
