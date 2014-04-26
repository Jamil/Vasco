#include <iostream>
#include "Data.h"
#include "StochasticLearner.h"

class Neuron {
  // A neuron contains
  //    Inputs – x_{i}
  //    Output - The result of applying a linear combination of x_{i}s to an activation function

public:
  Neuron();
  ~Neuron();
  float result(VSData &data);
  bool fired(VSData &data);

private:
  StochasticLearner *_learner;
};
