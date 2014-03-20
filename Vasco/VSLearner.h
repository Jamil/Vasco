//
//  VSLearner.h
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

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
    VSLearner(vector<const char*> &parameters, vector<VSData> *data, float learningRate, int IDENT);
    ~VSLearner();
    
    void update();
    double getHypothesisForData(const VSData &data);
    double setHypothesis(double (*hypothesis)(const VSData &data));
    
    int numParams();
    
protected:
    vector<VSData>          *_data;
    
    float                   _learningRate;
    
    // If you have multiple supervised values in a VSData, _IDENT identifies  which index of supervisedValues to learn from.
    int                     _IDENT;
    int                     _M;                  // Number of parameters
    double                  *_parameterValues;   // Parameter values
    vector<const char*>     _parameterNames;     // Parameter names (optional)
    
    double (*hypothesis)(const VSData &data);
};

#endif /* defined(__Vasco__VSLearner__) */
