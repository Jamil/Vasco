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
    VSBatchDescentLearner(int numParams, vector<VSData> *data, float learningRate);
    
    void update(float target);
    void updateUntilConvergence(float target);
    
private:
    double** updateParameters();
};


#endif /* defined(__Vasco__VSBatchDescentLearner__) */
