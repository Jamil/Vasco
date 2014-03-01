//
//  VSExplorer.h
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#ifndef __Vasco__VSExplorer__
#define __Vasco__VSExplorer__

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <curl/curl.h>

#include "VSLearner.h"
#include "VSParser.h"

using namespace std;

typedef enum category {
    Technology, News, Science, Sports
} Category;

class VSExplorer {
public:
    VSExplorer(string URL);
//    void queueURL(string URL);
    
private:
    bool active;
    
    void exploreURL(string URL, Category category);
    
    queue<string> nextURLs;
    
    VSParser *parser;
    VSLearner *learner[4];
    vector<VSData> data;
};

#endif /* defined(__Vasco__VSExplorer__) */
