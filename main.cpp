#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "VSData.h"
#include "StochasticLearner.h"
#include "BatchDescentLearner.h"
#include "Cluster.h"

using namespace std;

int main(int argc, const char * argv[])
{
  // Initialize sample training set
  const int set_size = 12;
  const int num_features = 3;
  
  // Distinctly can be separated into four groups; near origin, on z-axis, on x-axis, on y-axis
  float features[12][3] = {{1,1,12}, {2,1,12}, {-1, -1, 14}, {0,0,0}, {12,0,0}, {1,0,1}, {17,-2,-3}, {0,11,1}, {1,12,3}, {15,2,1}, {0,1,2}, {1,7,-1}};

  vector<VSData*> data;
  
  for (int i = 0; i < set_size; i++) {
    VSSupervisedData *newData = new VSSupervisedData(num_features);
    newData->setFeatures(num_features, features[i]);
    data.push_back(newData);
  }

  Cluster learner(4, data);
  learner.update();

  /*
  double* params = learner.params();
  for (int i = 0; i < learner.numParams(); i++) {
    cout << "Parameter " << i << ": " << params[i] << endl;
  }
  */

  for (int i = 0; i < set_size; i++) {
    delete data[i];
  }
  return 0;
}

