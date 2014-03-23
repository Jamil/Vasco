
#include "VSData.h"

#pragma mark - Constructors and Destructors

VSData::VSData(int features) {
    featureCount = features;
    
    _features = (float*)malloc(sizeof(float)*features);
    for (int i = 0; i < features; i++) {
        _features[i] = 0;
    }
    
    _learningValues = (float*)malloc(sizeof(float)*features);
    for (int i = 0; i < features; i++) {
        _learningValues[i] = 0;
    }
}

VSData::~VSData() {
    free(_features);
    free(_learningValues);
}

#pragma mark - Setters

void VSData::setFeatures(int num_features, float* features) {
    assert(num_features == featureCount);
    
    for (int i = 0; i < num_features; i++)
        _features[i] = features[i];
}

void VSData::setLearningValues(int num_values, float* learningValues) {
    assert(num_values == featureCount);
    
    for (int i = 0; i < featureCount; i++)
        _learningValues[i] = learningValues[i];
}

void VSData::setFeaturesAtIndex(int index, float value) {
    assert(index < featureCount);
    
    _features[index] = value;
}

void VSData::setLearningValueAtIndex(int index, float value) {
    assert(index < featureCount);

    _learningValues[index] = value;
}

#pragma mark - Getters

float* VSData::features() const {
    return _features;
}

float* VSData::learningValues() const {
    return _learningValues;
}

bool VSData::isSupervised() const {
    return supervised;
}
