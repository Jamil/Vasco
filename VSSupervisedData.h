
#ifndef __Vasco__VSSupervisedData__
#define __Vasco__VSSupervisedData__

#include <iostream>
#include "VSData.h"

using namespace std;

class VSSupervisedData : public VSData {
public:
  // Constructor 
  VSSupervisedData(int featureCount);
  VSSupervisedData(int featureCount, float* features, float supervisedValue);

  // Accessors
  void setSupervisedValue(float supervisedValue);
  float supervisedValue();

private:
  float _supervisedValue;
};

#endif
