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
#include <curl/curl.h>

using namespace std;

class VSExplorer {
public:
    VSExplorer(string URL);
    
    void stopExploring();
    void startExploring();
    
private:
    void exploreURL(string URL);
    
};

#endif /* defined(__Vasco__VSExplorer__) */
