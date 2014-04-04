#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "VSData.h"

using namespace std;

int main(int argc, const char * argv[])
{
  // Initialize sample training set
  const int set_size = 10;
  const int num_features = 3;
  float features[] = {1,2,3};

  vector<VSData*> data;
  
  for (int i = 0; i < set_size; i++) {
    VSData *newData = new VSData(num_features);
    newData->setFeatures(num_features, features);
    data.push_back(newData);
  }

  for (int i = 0; i < set_size; i++) {
    delete data[i];
  }
  return 0;
}

