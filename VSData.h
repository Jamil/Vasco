
#ifndef __Vasco__VSData__
#define __Vasco__VSData__

#include <iostream>
#include <vector>
#include <cassert>

#define PRINT_LOG

#ifdef PRINT_LOG
#define LOG(string, ...) printf(string, __VA_ARGS__)
#else
#define LOG(string, ...)
#endif

using namespace std;

class VSData {
public:
    VSData(int features);
    VSData(int feature_count, float* features);
    VSData(const VSData &oth); // cctor
    ~VSData();
    
    /* Accessors */
    float* features() const;
    int size();

    /* Mutators */
    void setFeaturesAtIndex(int index, float value);
    void setFeatures(int num_features, float* features);
    
protected:
    int featureCount; // Number of features
    float *_features; // Parameters; i.e., each theta_{i}
};

#endif /* defined(__Vasco__VSData__) */
