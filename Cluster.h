#include <iostream>
#include <vector>
#include <float.h>
#include "Data.h"

class Cluster {
public:
  Cluster(int k, vector<Data*> data);
  ~Cluster();
  void update();
  int classify(Data *data);
  float** centroids();

private:
  vector<Data*> _data;              // Training set (unsupervised)
  Data **_centroids;                // Dynamically allocated array of centroids
  vector<Data*> *_clusters;         // k clusters
  vector<Data*> *_clusters_prev;    // Previous state
  int _k;                             // Number of centroids ("k")

  void initializeCentroids();
  void updateUntilConvergence();
  bool step();
  double distance(Data* a, Data* b); 
  void updateCentroids();
};
