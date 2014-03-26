
#include "VSData.h"

#pragma mark - Constructors and Destructors

VSData::VSData(int features) {
    featureCount = features;
    
    _features = (float*)malloc(sizeof(float)*features);
    for (int i = 0; i < features; i++) {
        _features[i] = 0;
    }
}

VSData::~VSData() {
    free(_features);
}

#pragma mark - Setters

void VSData::setFeatures(int num_features, float* features) {
    assert(num_features == featureCount);
    
    for (int i = 0; i < num_features; i++)
        _features[i] = features[i];
}


void VSData::setFeaturesAtIndex(int index, float value) {
    assert(index < featureCount);
    
    _features[index] = value;
}

#pragma mark - Getters

float* VSData::features() const {
    return _features;
}
