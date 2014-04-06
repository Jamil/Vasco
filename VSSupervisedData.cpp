#include "VSSupervisedData.h"

VSSupervisedData::VSSupervisedData(int featureCount) : VSData(featureCount) {
}

void VSSupervisedData::setSupervisedValue(float supervisedValue) {
  _supervisedValue = supervisedValue;
}

float VSSupervisedData::supervisedValue() {
  return _supervisedValue;
}
