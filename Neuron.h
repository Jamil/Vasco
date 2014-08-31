#include <iostream>
#include "SupervisedData.h"
#include "StochasticLearner.h"
#include "Node.h"

class Neuron {
  // A neuron contains
  //    Inputs – x_{i}
  //    Raw Output - A linear combination of the x_{i}s and the parameters
  //    Output - The result of applying a linear combination of x_{i}s to an activation function

public:
  Neuron(int num_inputs, Node** inputs, Node* output);
  Neuron(int num_inputs, Node** inputs, Node* output, double (*activaion)(double input));
  ~Neuron();

  void update();
  void single_update();
  double sigmoid(double x);

private:
  int _num_inputs;
  double* parameters;
  double (*_activation)(double input);

  // Both of these really point to OutputNodes, but there's no access to the inputs' setter
  OutputNode** outputs;
  Node** inputs;
};
