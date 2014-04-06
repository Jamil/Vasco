//
//  VSStochasticLearner.h
//  Vasco
//
//  Created by Jamil Dhanani on 3/20/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#ifndef __Vasco__VSStochasticLearner__
#define __Vasco__VSStochasticLearner__

#include <iostream>
#include "VSLearner.h"

class VSStochasticLearner : public VSLearner {
public:
    VSStochasticLearner(int numParams, vector<VSSupervisedData*> data, float learningRate);
    
    void update();
    void updateUntilConvergence();
    double getHypothesisForData(VSData* data);

private:
    void step_stochastic(int i, int j, float target);
    double** updateParameters();
};

#endif
