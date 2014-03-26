
#ifndef __Vasco__VSLearner__
#define __Vasco__VSLearner__

#ifdef PRINT_LOG
#define LOG(string, ...) printf(string, __VA_ARGS__)
#else
#define LOG(string, ...)
#endif

#include <iostream>
#include <cassert>
#include <exception>
#include <cmath>
#include "VSData.h"

class VSLearner {
public:
    VSLearner(int numParams, vector<VSData> *data, float learningRate);
    ~VSLearner();
    
    virtual void update(float target);
    virtual double getHypothesisForData(const VSData &data);
    
    int numParams();
    
protected:
    vector<VSData>          *_data;
    
    float                   _learningRate;
    
    int                     _M;                  // Number of parameters
    double                  *_parameterValues;   // Parameter values
};

#endif /* defined(__Vasco__VSLearner__) */
