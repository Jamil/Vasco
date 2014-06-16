#include "Node.h"

double Node::getValues() {
  return _value;
}

void OutputNode::setValues(double value) {
  assert(value < 1);
  assert(value > 0);

  _value = value;
}
