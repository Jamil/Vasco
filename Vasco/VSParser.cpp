//
//  VSParser.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSParser.h"

VSParser::VSParser(vector<const char*> &parameters) {
    _parameters = parameters;
    for (int i = 0; i < parameters.size(); i++) {
        if (!_words.count(parameters.at(i))) {
            string str(parameters.at(i));
            _words.emplace(str, 0);
        }
    }
}

void VSParser::parseData(VSData &data) {
    // Ensure hash map is cleared
    for (int i = 0; i < _parameters.size(); i++) {
        _words[_parameters.at(i)] = 0;
    }
    
    for (int i = 0; i < data.words().size(); i++) {
        char* tofind = data.words().at(i);
        string tofind_cpy(tofind);
        
        for (int i = 0; tofind_cpy[i] != '\0'; i++) {
            tofind_cpy[i] = tolower(tofind_cpy[i]);
            if (!isalpha(tofind_cpy[i]))
                tofind_cpy.erase(i, 1);
        }
        if (_words.count(tofind_cpy)) {
            _words.at(tofind_cpy) += (float)1/data.words().size();
        }
    }
    
    for (int i = 0; i < _parameters.size(); i++) {
        float count = _words.at(_parameters.at(i));
        data.setFeaturesAtIndex(i, count);
    }
}