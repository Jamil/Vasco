#include "VSSupervisedData.h"

VSSupervisedData::VSSupervisedData(int featureCount) : VSData(featureCount) {
}

VSSupervisedData::VSSupervisedData(int featureCount, float* features, float supervisedValue) : VSData(featureCount, features) {
  _supervisedValue = supervisedValue;
}

void VSSupervisedData::setSupervisedValue(float supervisedValue) {
  _supervisedValue = supervisedValue;
}

float VSSupervisedData::supervisedValue() {
  return _supervisedValue;
}
