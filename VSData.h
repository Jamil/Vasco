
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
    
    /* Accessors */
    float* features() const;
    
    /* Mutators */
    void setFeaturesAtIndex(int index, float value);
    void setFeatures(int num_features, float* features);
    
protected:
    int featureCount; // Number of features
    float *_features; // Parameters; i.e., each theta_{i}
};

#endif /* defined(__Vasco__VSData__) */
