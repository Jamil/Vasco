
#include "Learner.h"

#define STOCHASTIC_TOLERANCE 0.00001

#pragma mark - Constructor and Destructor

Learner::Learner(int numParams, vector<SupervisedData*> data, float learningRate) {
    /* You can initialize a Learner with no data, but you should pass an empty vector rather than NULL. The training examples should be stored OUTSIDE of the class. */
    
    _learningRate = learningRate;
    _data = data;
    
    // Initialize x_{i} values to the zero vector
    _M = numParams;
    _parameterValues = (double*)malloc(sizeof(double) * _M);
    for (int i = 0; i < _M; i++)
        _parameterValues[i] = 0;

    _hypothesis = NULL;
}

Learner::Learner(int numParams, vector<SupervisedData*> data, float learningRate, float (*hypothesis)(float y)) {
    _learningRate = learningRate;
    _data = data;
    
    // Initialize x_{i} values to the zero vector
    _M = numParams;
    _parameterValues = (double*)malloc(sizeof(double) * _M);
    for (int i = 0; i < _M; i++)
        _parameterValues[i] = 0;

    _hypothesis = hypothesis;
}

Learner::~Learner() {
    delete _parameterValues;
}

#pragma mark - Public Functions

int Learner::numParams() {
    return _M;
}

double* Learner::params() {
  return _parameterValues;
}
