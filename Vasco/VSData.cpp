//
//  VSData.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSData.h"

VSData::VSData(char* __rawHtml, vector<double> &supervisedValues) {
    _rawHtml = __rawHtml;
    _content.assign(__rawHtml);
    
    _supervisedValues = supervisedValues;
}

void VSData::processContent() {
    /* Tokenize String */
    char* content_cstr = strdup(_content.c_str());
    char* elem = strtok(content_cstr, " ");
    
    while (elem) {
        _words.push_back(elem);
        elem = strtok(NULL, " ");
    }
}

vector<char*> VSData::words() const {
    return _words;
}

vector<int> VSData::features() const {
    return _features;
}

const char* VSData::content() const {
    return _content.c_str();
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

void VSData::setLearningValues(vector<double> learningValues) {
    _learningValues = learningValues;
}
