#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "VSData.h"
#include "VSStochasticLearner.h"

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

  VSStochasticLearner learner(3, data, 0.0001);
  learner.updateUntilConvergence(4);

  for (int i = 0; i < set_size; i++) {
    cout << "Hypothesis for Training Example " << i << ": ";
    int hyp = learner.getHypothesisForData(data[i]);
    cout << hyp << endl;
  }

  for (int i = 0; i < set_size; i++) {
    delete data[i];
  }
  return 0;
}

