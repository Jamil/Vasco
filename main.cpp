#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "VSData.h"
#include "VSStochasticLearner.h"
#include "VSBatchDescentLearner.h"
#include "VSCluster.h"

using namespace std;

int main(int argc, const char * argv[])
{
  // Initialize sample training set
  const int set_size = 10;
  const int num_features = 3;
  float features[] = {1,2,3};

  vector<VSSupervisedData*> data;
  
  for (int i = 0; i < set_size; i++) {
    VSSupervisedData *newData = new VSSupervisedData(num_features);
    newData->setFeatures(num_features, features);
    newData->setSupervisedValue((float)1/(i+1));
    data.push_back(newData);
  }

  VSCluster learner(3, data, 0.001);
  learner.update();

  double* params = learner.params();
  for (int i = 0; i < learner.numParams(); i++) {
    cout << "Parameter " << i << ": " << params[i] << endl;
  }

  for (int i = 0; i < set_size; i++) {
    delete data[i];
  }
  return 0;
}

