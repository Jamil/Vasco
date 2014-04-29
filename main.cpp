#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <readline/readline.h>
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

      set_size++;

      free(cline);
    }
    iris_data.close();
  }

  if (!data.size())
    return 1;

  // Repeatedly classify

  for (int p = 0; p < 10; p++) {
    Cluster learner(3, data);
    learner.update();
    float** centroids = learner.centroids();

    for (int i = 0; i < 3; i++) {
      cout << "Centroid " << i << endl;
      for (int j = 0; j < 4; j++) {
        cout << "\t" << centroids[i][j];
      }
      cout << endl;
    }

    for (int i = 0; i < 3; i++)
      free(centroids[i]);
    free(centroids);
    cout << endl << endl;
  }

  for (int i = 0; i < set_size; i++) {
    delete data[i];
  }
  return 0;
}
