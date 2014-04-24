//
//  BatchDescentLearner.h
//  Vasco
//
//  Created by Jamil Dhanani on 3/20/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#ifndef __Vasco__BatchDescentLearner__
#define __Vasco__BatchDescentLearner__

#include <iostream>
#include "Learner.h"

class BatchDescentLearner : public Learner {
public:
    BatchDescentLearner(int numParams, vector<SupervisedData*> data, float learningRate);
    BatchDescentLearner(int numParams, vector<SupervisedData*> data, float learningRate, float (*hypothesis)(float y));
    
    void update();
    void updateUntilConvergence();

    double getHypothesisForData(Data* data);   
private:
    double** updateParameters();
};


#endif /* defined(__Vasco__BatchDescentLearner__) */
