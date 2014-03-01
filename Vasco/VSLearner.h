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
#include "VSData.h"

class VSLearnerException : exception {};
class VSLearnerExceptionNoData : VSLearnerException {
    virtual const char* what() const throw() {
        return "No VSData passed to constructor";
    }
} vs_learner_exception_no_data;

class VSLearner {
public:
    VSLearner(vector<char*> &parameters, vector<VSData> *data, float learningRate);
    
    vector<double>* updateParameters();
    double getHypothesisForData(const VSData &data);
    
private:
    vector<VSData>  *_data;
    
    float           _learningRate;
    
    int             _M;                  // Number of parameters
    vector<double>  _parameterValues;    // Parameter values
    vector<char*>   _parameterNames;     // Parameter names (optional)
    
    double _sum_err_tr(int index);
};

#endif /* defined(__Vasco__VSLearner__) */
