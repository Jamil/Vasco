#include <iostream>

class Node {
public:
  Node(int size, Neuron* source, Neuron* destination);

  double* getValue();
  
  Neuron* _source;
  Neuron** _destinations;

protected:
  int _size;
  int _num_destinations;
  double _value;
}

class OutputNode : Node {
public:
  void setValue(double value);
}
