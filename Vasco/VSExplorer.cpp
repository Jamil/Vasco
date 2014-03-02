//
//  VSExplorer.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include "VSExplorer.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

VSExplorer::VSExplorer(string URL) {
    active = true;
    
    // Initialize dictionary
    vector<const char*> dict;
    
    ifstream in("/Users/jamildhanani/Developer/C++/Projects/Vasco/Vasco/nounlist");
    if (in.fail()) {
        cout << "ERROR" << endl;
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
    
    parser = new VSParser(dict);
    VSParser parser(dict);
    
    for (int i = 0; i < 4; i++) {
        learner[i] = new VSLearner(dict, &data, 10, i);
    }
    
    string URLs[4] = {
        "http://www.reddit.com/r/technology/.json",
        "http://www.reddit.com/r/worldnews/.json",
        "http://www.reddit.com/r/science/.json",
        "http://www.reddit.com/r/sports/.json"
    };
    
    for (int i = 0; i < 4; i++) {
        CURL *curl;
        CURLcode res;
        string readBuffer;
        
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, URLs[i].c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
        
        int index = 0;
        int count = 0;
        while (index != -1 && count < 3) {
            index = (int)readBuffer.find("\"url\":");
            if (index != -1) {
                int start = index + 8;
                int len;
                for (len = 0; readBuffer[start + len] != '\"'; len++);
                //cout << readBuffer.substr(start, len) << endl;
                
                exploreURL(readBuffer.substr(start, len), (Category)i);
                
                readBuffer = readBuffer.substr(start + len, string::npos);
            }
            count++;
        }
    }
    
    active = false;
}

void VSExplorer::exploreURL(string URL, Category category) {
    cout << (int)category << " Exploring " << URL << endl;
    
    CURL *curl;
    CURLcode res;
    string readBuffer;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    
    vector<double> supervisedValues = {-1, -1, -1, -1};
    supervisedValues[(int)category] = 1;
    
    VSData newData(strdup(readBuffer.c_str()), supervisedValues, learner[0]->numParams());
    newData.processContent();
    parser->parseData(newData);
    
    if (newData.words().size() > 100) {
        data.push_back(newData);
        
        for (int i = 0; i < 4; i++) {
            cout << "Running Learner " << i << endl;
            double hyp = learner[i]->getHypothesisForData(data.back());
            cout << "Guess: " << hyp << endl;
            
            learner[i]->updateUntilConvergence(0.5);
            
            hyp = learner[i]->getHypothesisForData(data.back());
            cout << "Revised: " << hyp << endl;
        }
    }
}

void VSExplorer::examineURL(string URL) {
    cout << " Exploring " << URL << endl;
    
    CURL *curl;
    CURLcode res;
    string readBuffer;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    
    vector<double> supervisedValues = {0, 0, 0, 0};
    
    VSData newData(strdup(readBuffer.c_str()), supervisedValues, learner[0]->numParams());
    newData.processContent();
    parser->parseData(newData);
    
    for (int i = 0; i < 4; i++) {
        double hyp = learner[i]->getHypothesisForData(newData);
        cout << "Category " << i << ": " << hyp << endl;
    }
}
