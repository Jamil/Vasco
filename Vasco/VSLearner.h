//
//  VSLearner.h
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#ifndef __Vasco__VSLearner__
#define __Vasco__VSLearner__

#include <iostream>
#include <cassert>
#include <exception>
#include <cmath>
#include "VSData.h"

class VSLearner {
public:
    VSLearner(vector<const char*> &parameters, vector<VSData> *data, float learningRate, int IDENT);
    
    void updateUntilConvergence(float tolerance);
    double** updateParameters();
    double getHypothesisForData(const VSData &data);
    
private:
    vector<VSData>          *_data;
    
    float                   _learningRate;
    int                     _IDENT;
    int                     _M;                  // Number of parameters
    double                  *_parameterValues;   // Parameter values
    vector<const char*>     _parameterNames;     // Parameter names (optional)
    
    double _sum_err_tr(int index);
};

#endif /* defined(__Vasco__VSLearner__) */
