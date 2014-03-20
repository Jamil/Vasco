//
//  VSData.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSData.h"

#pragma mark - Constructors and Destructors

VSData::VSData(int features) {
    supervised = false;
    featureCount = features;
    
    _features = (float*)malloc(sizeof(float)*features);
    for (int i = 0; i < features; i++) {
        _features[i] = 0;
    }
}

#pragma mark - Setters

void VSData::setSupervised(vector<double> &supervisedValues) {
    supervised = true;
    _supervisedValues = supervisedValues;
}

void VSData::setLearningValues(vector<double> learningValues) {
    _learningValues = learningValues;
}

void VSData::setFeaturesAtIndex(int index, float value) {
    _features[index] = value;
}

void VSData::setFeatures(int num_features, float* features) {
    assert(num_features == featureCount);
    
    for (int i = 0; i < num_features; i++)
        _features[i] = features[i];
}

#pragma mark - Getters

float* VSData::features() const {
    return _features;
}

vector<double> VSData::learningValues() const {
    return _learningValues;
}

vector<double> VSData::supervisedValues() const {
    return _supervisedValues;
}

void VSData::setLearningValueAtIndex(int index, float value) {
    _learningValues.at(index) = value;
}

bool VSData::isSupervised() const {
    return supervised;
}
