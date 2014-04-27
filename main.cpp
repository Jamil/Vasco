#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Data.h"
#include "Cluster.h"

using namespace std;

int main() {
  int set_size = 0;
  int num_features = 4;
  ifstream iris_data("iris.txt");
  vector<Data*> data;

  string line;
  if (iris_data.is_open()) {
    while ( getline (iris_data,line) )
    {
      if (!line.length())
        break;

      char* cline = strdup(line.c_str());
      char* elem = strtok(cline, ",");
      
      float vals[4] = {0};
      for (int i = 0; i < 4; i++) {
        vals[i] = atof(elem);
        elem = strtok(NULL, ",");
      }
      
      Data *newData = new Data(num_features);
      newData->setFeatures(num_features, vals);
      data.push_back(newData);

      free(cline);
    }
    iris_data.close();
  }

  if (!data.size())
    return 1;

  Cluster learner(4, data);
  learner.update();

  for (int i = 0; i < set_size; i++) {
    delete data[i];
  }
  return 0;
}
