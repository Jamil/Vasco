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
    int             *_features; // 'Word count'
    
    /* Assigned Learning Values */
    vector<double> _learningValues;
    
    /* Actual Values (if applicable) */
    vector<double> _supervisedValues;
    
public:
    /* Accessors */
    vector<char*>   words() const;
    int*            features() const;
    const char*     content() const;
    vector<double>  learningValues() const;
    vector<double>  supervisedValues() const;
    
    /* Mutators */
    void setLearningValueAtIndex(int index, float value);
    void setLearningValues(vector<double> learningValues);
    void setFeaturesAtIndex(int index, int value);
    
};

#endif /* defined(__Vasco__VSData__) */
