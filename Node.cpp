#include "Node.h"

Node::Node(int _num_destinations, Neuron* source, Neuron** destinations) {
  _value = 0;
  _source = source;

  for (int i = 0; i < _num_destinations; i++)
    _destinations[i] = destinations[i];
}

double Node::getValue() {
  return _value >= 0.5 ? 1.0 : 0.0;
}

void OutputNode::setValues(double value) {
  assert(value < 1);
  assert(value > 0);

  _value = value;
}
