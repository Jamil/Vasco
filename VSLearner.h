
#ifndef __Vasco__VSLearner__
#define __Vasco__VSLearner__

#define PRINT_LOG

#ifdef PRINT_LOG
#define LOG(string, ...) printf(string, __VA_ARGS__)
#else
#define LOG(string, ...)
#endif

#include <iostream>
#include <cassert>
#include <exception>
#include <cmath>
#include "VSSupervisedData.h"

class VSLearner {
public:
    VSLearner(int numParams, vector<VSSupervisedData*> data, float learningRate);
    VSLearner(int numParams, vector<VSSupervisedData*> data, float learningRate, float (*hypothesis)(float y));
    ~VSLearner();
    
    virtual void update() = 0;
    virtual double getHypothesisForData(VSData* data) = 0;

    int numParams();
    double* params();
    
protected:
    vector<VSSupervisedData*> _data;

    float (*_hypothesis)(float y);
    
    float _learningRate;
    int _M;                     // Number of parameters
    double *_parameterValues;   // Parameter values
};

#endif /* defined(__Vasco__VSLearner__) */
