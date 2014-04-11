#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "VSCluster.h"

VSCluster::VSCluster(int k, vector<VSData*> data) {
  _data = data;
  _k = k;
  _centroids = (VSData**)malloc(sizeof(VSData*)*k);
  _clusters = new vector<VSData*>[k];

  // Initialize centroids
  srand(time(NULL));
  for (int i = 0; i < _k; i++) {
    int index = rand() % _data.size();
    _centroids[i] = _data.at(index);
  }
}

void VSCluster::update() {
  updateUntilConvergence();
}

double VSCluster::distance(const VSData* a, const VSData* b) {
  int n = a->size();
  int m = b->size();

  assert(m == n);

  float* aFeatures = a->features();
  float* bFeatures = b->features();

  double result = 0;
  for (int i = 0; i < n; i++) {
    double diff = (aFeatures[i] - bFeatures[i]);
    diff *= diff;
    result += diff;
  }
  
  return sqrt(result);
}

void VSCluster::step() {
  int set_size = _data.size();
  for (int i = 0; i < set_size; i++) {
    double minDist = +inf;
    vector<VSData*> *closestCluster;

    for (int j = 0; j < _k; j++) {
      double dist = distance(_data.at(i), _centroids[j]);
      if (dist < minDist) {
        minDist = dist;
        closestCluster = _clusters[j];
      }
    }
    // add to closest cluster
    closestCluster->push_back(_data.at(i));
  }
}

void VSCluster::updateUntilConvergence() {
  bool converged = false;
  while (!converged) {
    converged = step();         // Assign clusters 
    updateCentroids();
  }
}

