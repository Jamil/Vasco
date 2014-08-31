#include "Neuron.h"

Neuron(int num_inputs, Node** inputs, Node* output) {
  // Default to the sigmoid function as the activation function
  _activation = sigmoid;
}

Neuron(int num_inputs, Node** inputs, Node* output, double (*activaion)(double input)) {
  _activation = activation;
}

double Neuron::sigmoid(double x) {
  double denom = 1 + exp(-1*x);
  return 1/denom;
}

void Neuron::single_update() {
  double linear_combination;
  for (int i = 0; i < _num_inputs; i++)
    linear_combination += parameters[i] * inputs[i]->getValue();
  
  double result = sigmoid(linear_combination);
  
  output->setValue(result);
}

bool Neuron::is_active() {
  return output;
}
