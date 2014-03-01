//
//  main.cpp
//  Vasco
//
//  Created by Jamil Dhanani on 2/28/2014.
//  Copyright (c) 2014 Jamil Dhanani. All rights reserved.
//

#include <iostream>
#include "VSData.h"

int main(int argc, const char * argv[])
{
    char test[] = "The quick brown fox jumps over the lazy dog.";
    vector<double> supervisedValues;
    
    VSData *data = new VSData(test, supervisedValues);
    data->processContent();
    
    for (int i = 0; i < data->words().size(); i++) {
        cout << data->words().at(i) << endl;
    }
    return 0;
}

