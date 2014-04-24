
#ifndef __Vasco__Learner__
#define __Vasco__Learner__

#include <iostream>
#include <cassert>
#include <exception>
#include <cmath>
#include "SupervisedData.h"

class Learner {
public:
    Learner(int numParams, vector<SupervisedData*> data, float learningRate);
    Learner(int numParams, vector<SupervisedData*> data, float learningRate, float (*hypothesis)(float y));
    ~Learner();
    
    virtual void update() = 0;
    virtual double getHypothesisForData(Data* data) = 0;

    int numParams();
    double* params();
    
protected:
    vector<SupervisedData*> _data;

    float (*_hypothesis)(float y);
    
    float _learningRate;
    int _M;                     // Number of parameters
    double *_parameterValues;   // Parameter values
};

#endif /* defined(__Vasco__Learner__) */
