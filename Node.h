#include <iostream>

class Node {
public:
  double* getValue();

protected:
  int _size;
  double _value;
}

class OutputNode : Node {
public:
  void setValue(double value);
}
