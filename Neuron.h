#include <iostream>
#include "Data.h"
#include "VSStochasticLearner.h"

class Neuron {
  // A neuron contains
  //    Inputs – x_{i}
  //    Output - The result of applying a linear combination of x_{i}s to an activation function

public:
  Neuron();
  ~Neuron();
  float input(float* x);

private:
  VSStochasticLearner *_learner;

};
