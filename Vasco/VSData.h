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

using namespace std;

class VSData {
public:
    VSData(char* _rawHtml, vector<double> &supervisedValues, int features);
    
    void processContent();
    
private:
    /* Metadata */
    string _contentTitle;
    string _url;
    bool supervised;
    
    /* Intrinisic Data */
    char*           _rawHtml;
    string          _content;
    vector<char*>   _words;
    float           *_features; // 'Word count'
    
    /* Assigned Learning Values */
    vector<double> _learningValues;
    
    /* Actual Values (if applicable) */
    vector<double> _supervisedValues;
    
public:
    /* Accessors */
    vector<char*>   words() const;              // Parsed words
    float*          features() const;           // Weights for each feature
    const char*     content() const;            // Content
    vector<double>  learningValues() const;     // Hypotheses
    vector<double>  supervisedValues() const;   // Targets
    
    /* Mutators */
    void setLearningValueAtIndex(int index, float value);
    void setLearningValues(vector<double> learningValues);
    void setFeaturesAtIndex(int index, float value);
    
};

#endif /* defined(__Vasco__VSData__) */
