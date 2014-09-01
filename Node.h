#include <iostream>

class Node {
public:
  Node(int _num_destinations, Neuron* source, Neuron* destination);

  double* getValue();
  
  Neuron* _source;
  Neuron** _destinations;

protected:
  int _num_destinations;
  double _value;
}

class OutputNode : Node {
public:
  OutputNode(int _num_destinations, Neuron* source, Neuron* destination);

  void setValue(double value);
}
