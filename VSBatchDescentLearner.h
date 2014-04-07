//
//  VSBatchDescentLearner.h
//  Vasco
//
//  Created by Jamil Dhanani on 3/20/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#ifndef __Vasco__VSBatchDescentLearner__
#define __Vasco__VSBatchDescentLearner__

#include <iostream>
#include "VSLearner.h"

class VSBatchDescentLearner : public VSLearner {
public:
    VSBatchDescentLearner(int numParams, vector<VSSupervisedData*> data, float learningRate);
    VSBatchDescentLearner(int numParams, vector<VSSupervisedData*> data, float learningRate, float (*hypothesis)(float y));
    
    void update();
    void updateUntilConvergence();

    double getHypothesisForData(VSData* data);   
private:
    double** updateParameters();
};


#endif /* defined(__Vasco__VSBatchDescentLearner__) */
