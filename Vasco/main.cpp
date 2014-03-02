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
    
    bool quit = false;
    while (!quit) {
        char* line = (char*)malloc(sizeof(char)*100);
        size_t nbytes = 99;
        printf(">> ");
        getline(&line, &nbytes, stdin);
        for (int i = 0; i < strlen(line); i++)
            if (line[i] == '\n')
                line[i] = '\0';
        if (!strcmp(line, "quit"))
            quit = true;
        explorer.examineURL(line);
        free(line);
    }
    
    return 0;
}

