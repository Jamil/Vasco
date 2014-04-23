#include <iostream>
#include <vector>
#include <float.h>
#include "VSData.h"

class Cluster {
public:
  Cluster(int k, vector<VSData*> data);
  ~Cluster();
  void update();

private:
  vector<VSData*> _data;              // Training set (unsupervised)
  VSData **_centroids;                // Dynamically allocated array of centroids
  vector<VSData*> *_clusters;         // k clusters
  vector<VSData*> *_clusters_prev;    // Previous state
  int _k;                             // Number of centroids ("k")

  void initializeCentroids();
  void updateUntilConvergence();
  bool step();
  double distance(VSData* a, VSData* b); 
  void updateCentroids();
};
