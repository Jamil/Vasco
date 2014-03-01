//
//  VSParser.h
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#ifndef __Vasco__VSParser__
#define __Vasco__VSParser__

#include <iostream>
#include <vector>
#include <unordered_map>

#include "VSData.h"

using namespace std;

/* Minimal implementation right now, but this is made in the interests of scalability if we need to add more parameters and parse more data from the article. */

class VSParser {
public:
    VSParser(vector<const char*> &parameters);
    void parseData(VSData &data);
    
private:
    unordered_map<string, int> _words;
    vector<const char*> _parameters;
};

#endif /* defined(__Vasco__VSParser__) */
