#include <iostream>
#include <vector>
#include "VSData.h"

class VSCluster {
public:
  VSCluster(int k, vector<VSData*> data);
  void update();

private:
  vector<VSData*> _data; // Training set (unsupervised)
  VSData *_centroids;    // Dynamically allocated array of centroids
  int _k;               // Number of centroids ("k")
  void VSCluster::updateUntilConvergence();
}
