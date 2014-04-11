#include <iostream>
#include <vector>
#include "VSData.h"

class VSCluster {
public:
  VSCluster(int k, vector<VSData*> data);
  void update();

private:
  vector<VSData*> _data;              // Training set (unsupervised)
  VSData **_centroids;                // Dynamically allocated array of centroids
  vector<VSData*> *_clusters;         // k clusters
  vector<VSData*> *_clusters_prev;    // Previous state
  int _k;                             // Number of centroids ("k")

  void updateUntilConvergence();
  void step();
  void distance(const VSData* a, const VSData* b); 
};
