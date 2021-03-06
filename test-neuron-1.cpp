/*
 * Basic test for the functionality of a neuron
 */

#include <iostream>
#include "Node.h"
#include "Neuron.h"

#define NUM_INPUTS 5

int main() {
  // Declare pointer to neuron
  Neuron* neuron = NULL;

  // Declare pointers to input nodes
  Node** inputs = new Node[NUM_INPUTS]
  for (int i = 0; i < NUM_INPUTS; i++)
    inputs[i] = new Node(1, NULL, &neuron)

  // Declare output node
  Node* output = new OutputNode(0, NULL, NULL);
}
