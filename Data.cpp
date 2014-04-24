
#include "Data.h"

#pragma mark - Constructors and Destructors

Data::Data(int features) {
    featureCount = features;
    
    _features = (float*)malloc(sizeof(float)*features);
    for (int i = 0; i < features; i++) {
        _features[i] = 0;
    }
}

Data::Data(int feature_count, float* features) {
  featureCount = feature_count;
  _features = (float*)malloc(sizeof(float)*feature_count);
  for (int i = 0; i < feature_count; i++)
    _features[i] = features[i];
}

Data::Data(const Data &oth) {
  this->featureCount = oth.featureCount;
  this->_features = (float*)malloc(sizeof(float)*oth.featureCount);
  for (int i = 0; i < this->featureCount; i++)
    this->_features[i] = oth._features[i];
}

Data::~Data() {
  free(_features);
}

#pragma mark - Setters

void Data::setFeatures(int num_features, float* features) {
    assert(num_features == featureCount);
    
    for (int i = 0; i < num_features; i++)
        _features[i] = features[i];
}


void Data::setFeaturesAtIndex(int index, float value) {
    assert(index < featureCount);
    
    _features[index] = value;
}

#pragma mark - Getters

float* Data::features() const {
    return _features;
}

int Data::size() {
  return featureCount;
}
