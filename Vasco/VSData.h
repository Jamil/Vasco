
#ifndef __Vasco__VSData__
#define __Vasco__VSData__

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class VSData {
public:
    VSData(int features);
    ~VSData();
    
private:
    /* Metadata */
    bool supervised;
    int featureCount;
    
    /* Intrinisic Data (each theta_{i}) */
    float          *_features; // 'Word count'
    
    /* Assigned Learning Values/Weights (each x_{i}) */
    float          *_learningValues;
    
public:
    /* Accessors */
    float*          features() const;
    float*          learningValues() const;
    bool            isSupervised() const;
    
    /* Mutators */
    void setLearningValueAtIndex(int index, float value);
    void setLearningValues(int num_values, float* learningValues);
    void setFeaturesAtIndex(int index, float value);
    void setFeatures(int num_features, float* features);
};

#endif /* defined(__Vasco__VSData__) */
