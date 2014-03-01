//
//  main.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 3/1/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "VSExplorer.h"
#include "VSParser.h"
#include "VSLearner.h"

using namespace std;

int main(int argc, const char * argv[])
{
    VSExplorer explorer("http://www.reddit.com/r/technology/.json");
    /*
    vector<const char*> dict;

    ifstream in("/Users/jamildhanani/Developer/C++/Projects/Vasco/Vasco/web2");
    if (in.fail()) {
        cout << "ERROR" << endl;
        return 0;
    }
    string token;
    while (in >> token) {
        //printf("%s\n", token.c_str());
        if (token.c_str()) {
            char* newstr = strdup(token.c_str());
            newstr[0] = tolower(newstr[0]);
            //cout << newstr << endl;
            dict.push_back(newstr);
        }
    }
    
    VSParser parser(dict);
    
    vector<double> supervisedValues[3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 1, 0}
    };
    
    vector<VSData> data;
    for (int i = 0; i < 3; i++) {
        VSData sampleData(text[i], supervisedValues[i], (int)dict.size());
        sampleData.processContent();
        parser.parseData(sampleData);
        
        data.push_back(sampleData);
    }
    
    VSLearner learner(dict, &data, 0.01, 1);
    learner.updateUntilConvergence(0.15);
    cout << learner.getHypothesisForData(data.at(1)) << endl;
    */
    return 0;
}

