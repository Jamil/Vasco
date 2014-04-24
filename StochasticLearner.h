//
//  StochasticLearner.h
//  Vasco
//
//  Created by Jamil Dhanani on 3/20/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#ifndef __Vasco__StochasticLearner__
#define __Vasco__StochasticLearner__

#include <iostream>
#include "Learner.h"

class StochasticLearner : public Learner {
public:
    StochasticLearner(int numParams, vector<SupervisedData*> data, float learningRate);
    
    void update();
    void updateUntilConvergence();
    double getHypothesisForData(Data* data);

private:
    void step_stochastic(int i, int j, float target);
    double** updateParameters();
};

#endif
