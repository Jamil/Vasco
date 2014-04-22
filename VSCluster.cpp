#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <set>
#include "VSCluster.h"

VSCluster::VSCluster(int k, vector<VSData*> data) {
  _data = data;
  _k = k;
  _centroids = (VSData**)malloc(sizeof(VSData*)*k);
  _clusters = new vector<VSData*>[k];
  _clusters_prev = new vector<VSData*>[k];

  // Number of clusters must be less than size of training set
  assert(k <= data.size());
  initializeCentroids();
}

VSCluster::~VSCluster() {
  for (int i = 0; i < _k; i++) {
    if (_centroids[i])
      delete _centroids[i];
  }
  delete [] _centroids;
  delete [] _clusters;
  delete [] _clusters_prev;
}

void VSCluster::initializeCentroids() {
  // Initialize centroids
  srand(time(NULL));
  set<int> chosen;

  VSData *previous = NULL;

  int index = -1;
  for (int i = 0; i < _k; i++) {
    float weights[_data.size()]; 
    
    if (!previous) {
      // Initialize index to random data point
      index = rand() % _data.size();
    }
    else {
      // Assign a weight proportional to the square of the distance to last chosen point
      float sum = 0;
      for (int j = 0; j < _data.size(); j++) {
        weights[j] = distance(_data.at(j), previous);
        weights[j] *= weights[j];
        sum += weights[j];
        LOG("Training example %d, weight %f\n", j, weights[j]);
      }

      // Now select a training example at random
      float random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/sum));
      LOG("Random value: %f\n", random);
      bool duplicate = false;
      do {
        duplicate = false;
        for (int j = 0; j < _data.size(); j++) {
          if (random < weights[j]) {
            LOG("Selecting %d\n", j);
            index = j;
            break;
          }
          else {
            random -= weights[j];
          }
        }

        if (chosen.count(index)) {
          random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/sum));
          duplicate = true;
          LOG("Duplicate. Trying again.\n", NULL);
          LOG("Random value: %f\n", random);
        }
      } while (duplicate);
    }

    chosen.insert(index);

    float* features = _data.at(index)->features();
    int size = _data.at(index)->size();
    _centroids[i] = new VSData(size, features);
    previous = _centroids[i];

    LOG("Initializing cluster %d to:\n", i);
    for (int j = 0; j < size; j++)
      LOG("\t%d:%f", j, features[j]);
    LOG("\n", NULL);
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

  for (int i = 0; i < _k; i++) {
    _clusters[i].clear();
  }

  for (int i = 0; i < set_size; i++) {
    vector<VSData*> *closestCluster;
    int cc = -1;
    double minDist = DBL_MAX;

    for (int j = 0; j < _k; j++) {
      double dist = distance(_data.at(i), _centroids[j]);
      if (dist < minDist) {
        minDist = dist;
        closestCluster = &_clusters[j];
        cc = j;
      }
    }

    // add to closest cluster
    closestCluster->push_back(_data.at(i));
  }
  LOG("Reassigned data set.\n", NULL);
 
  // Check to see if no change
  LOG("Checking for convergence\n", NULL);
  for (int i = 0; i < _k; i++) {
    LOG("Cluster %d\n", i);
    int vecSize = _clusters[i].size();
    int prevSize = _clusters_prev[i].size();
  
    LOG("Previous size: %d, Current size: %d\n", prevSize, vecSize);
    if (vecSize != prevSize)
      return false;

    LOG("Comparison:\n", NULL);
    for (int j = 0; j < vecSize; j++) {
      LOG("\t0x%lx\t0x%lx\n", (unsigned long int)(_clusters_prev[i].at(j)), (unsigned long int)(_clusters[i].at(j)));
      if (_clusters_prev[i].at(j) != _clusters[i].at(j))
        return false;
    }
    LOG("\n", NULL);
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
  
  int size = _centroids[0]->size();
  LOG("Converged;\n", NULL);
  for (int i = 0; i < _k; i++) {
    for (int j = 0; j < size; j++)
      LOG("\t%d:%f", j, _centroids[i]->features()[j]);
    LOG("\n", NULL);
  }
}

