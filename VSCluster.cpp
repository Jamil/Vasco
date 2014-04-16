#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "VSCluster.h"

VSCluster::VSCluster(int k, vector<VSData*> data) {
  _data = data;
  _k = k;
  _centroids = (VSData**)malloc(sizeof(VSData*)*k);
  _clusters = new vector<VSData*>[k];
  _clusters_prev = new vector<VSData*>[k];

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

double VSCluster::distance(VSData* a, VSData* b) {
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

bool VSCluster::step() {
  int set_size = _data.size();
  
  // Copy current state to previous state
  LOG("New Iteration\n", NULL);
  for (int i = 0; i < _k; i++) {
    _clusters_prev[i].clear();
    int vecSize = _clusters[i].size();
    int count = 0;
    for (int j = 0; j < vecSize; j++) {
      _clusters_prev[i].push_back(_clusters[i].at(j));
      count++;
    }
    LOG("Cluster %d : %d\n", i, count);
  }
  LOG("\n", NULL);

  for (int i = 0; i < set_size; i++) {
    _clusters[i].clear();
    double minDist = 10000000; // Large number; need to fix
    vector<VSData*> *closestCluster;

    for (int j = 0; j < _k; j++) {
      double dist = distance(_data.at(i), _centroids[j]);
      if (dist < minDist) {
        minDist = dist;
        closestCluster = &_clusters[j];
      }
    }
    // add to closest cluster
    closestCluster->push_back(_data.at(i));
  }
 
  // Check to see if no change
  for (int i = 0; i < _k; i++) {
    int vecSize = _clusters[i].size();
    int prevSize = _clusters_prev[i].size();

    if (vecSize != prevSize)
      return false;

    for (int j = 0; j < vecSize; j++) {
      if (_clusters_prev[i].at(j) != _clusters[i].at(j))
        return false;
    }
  }

  return true; // return true if no change
}

void VSCluster::updateCentroids() {
  // Examine first training example to get feature count, etc 
  if (!_data.size())
    return;

  int featureCount = _data.at(0)->size();

  // O(scary)
  for (int i = 0; i < _k; i++) {
    int clusterSize = _clusters[i].size();
    float sums[featureCount];
    memset(sums, 0, sizeof(sums));
    for (int j = 0; j < clusterSize; j++) {
      VSData *currentData = _clusters[i].at(j);
      float *currentFeatures = currentData->features();
      for (int n = 0; n < featureCount; n++) {
        sums[n] += currentFeatures[n];
      }
    }
    for (int j = 0; j < featureCount; j++) {
      sums[j] /= clusterSize;
    }
    if (_centroids[i])
      delete _centroids[i];
    _centroids[i] = new VSData(featureCount, sums);
  }
}

void VSCluster::updateUntilConvergence() {
  bool converged = false;
  do {
    converged = step();         // Assign clusters 
    updateCentroids();
  } while (!converged);
}

