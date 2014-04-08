#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "VSCluster.h"

VSCluster::VSCluster(int k, vector<VSData*> data) {
  _data = data;
  _k = k;
  _centroids = new VSData[k];
}

VSCluster::update() {
  // Initialize centroids
  srand(time(NULL));
  for (int i = 0; i < _k; i++) {
    int index = rand() % _data.size();
    _centroids[i] = _data.at(index);
  }

  updateUntilConvergence();
}

VSCluster::updateUntilConvergence() {
  bool converged = false;

  while (!converged) {
    
    // For each centroid, assign a subset of the training set to it
    for (int i = 0; i < _k; i++) {
        
    }

  }
}
