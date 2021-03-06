#include "Node.h"

Node::Node(int _num_destinations, Neuron* source, Neuron** destinations) {
  _value = 0;
  _source = source;

  for (int i = 0; i < _num_destinations; i++)
    _destinations[i] = destinations[i];
}

double Node::getValue() {
  return _value;
}

OutputNode::OutputNode(int _num_destinations, Neuron* source, Neuron** destinations) : Node(_num_destinations, source, destinations) {
}

void OutputNode::setValue(double value) {
  if (value > 1)
    _value = 1;
  else if (value < 0)
    _value = 0;
  else
    _value = value;
}
