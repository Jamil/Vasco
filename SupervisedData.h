
#ifndef __Vasco__SupervisedData__
#define __Vasco__SupervisedData__

#include <iostream>
#include "Data.h"

using namespace std;

class SupervisedData : public Data {
public:
  // Constructor 
  SupervisedData(int featureCount);
  SupervisedData(int featureCount, float* features, float supervisedValue);

  // Accessors
  void setSupervisedValue(float supervisedValue);
  float supervisedValue();

private:
  float _supervisedValue;
};

#endif
