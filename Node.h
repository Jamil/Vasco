#include <iostream>

class Node {
protected:
  int size;
  double* values;
}

class OutputNode : Node {
public:
  void setValues(double* values);
}
