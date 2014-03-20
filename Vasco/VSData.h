//
//  VSData.h
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#ifndef __Vasco__VSData__
#define __Vasco__VSData__

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class VSData {
public:
    VSData(int features);
    
private:
    /* Metadata */
    bool supervised;
    int featureCount;
    
    /* Intrinisic Data */
    float           *_features; // 'Word count'
    
    /* Assigned Learning Values */
    vector<double>  _learningValues;
    
    /* Actual Values (if applicable) */
    vector<double>  _supervisedValues;
    
public:
    /* Accessors */
    float*          features() const;           // Weights for each feature
    vector<double>  learningValues() const;     // Hypotheses
    vector<double>  supervisedValues() const;   // Targets
    bool            isSupervised() const;
    
    /* Mutators */
    void setLearningValueAtIndex(int index, float value);
    void setLearningValues(vector<double> learningValues);
    void setFeaturesAtIndex(int index, float value);
    void setFeatures(int num_features, float* features);
    void setSupervised(vector<double> &supervisedValues);
};

#endif /* defined(__Vasco__VSData__) */
