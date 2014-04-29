
#ifndef __Vasco__Data__
#define __Vasco__Data__

#include <iostream>
#include <vector>
#include <cassert>

//#define PRINT_LOG

#ifdef PRINT_LOG
#define LOG(string, ...) printf(string, __VA_ARGS__)
#else
#define LOG(string, ...)
#endif

using namespace std;

class Data {
public:
    Data(int features);
    Data(int feature_count, float* features);
    Data(const Data &oth); // cctor
    ~Data();
    
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

#endif /* defined(__Vasco__Data__) */
