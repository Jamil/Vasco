#include "SupervisedData.h"

SupervisedData::SupervisedData(int featureCount) : Data(featureCount) {
}

SupervisedData::SupervisedData(int featureCount, float* features, float supervisedValue) : Data(featureCount, features) {
  _supervisedValue = supervisedValue;
}

void SupervisedData::setSupervisedValue(float supervisedValue) {
  _supervisedValue = supervisedValue;
}

float SupervisedData::supervisedValue() {
  return _supervisedValue;
}
