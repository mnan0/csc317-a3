#include "DirectionalLight.h"
#include <limits>

void DirectionalLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
  ////////////////////////////////////////////////////////////////////////////
  max_t = std::numeric_limits<double>::max();
  d = q + (-1.0)*(this->d);
  ////////////////////////////////////////////////////////////////////////////
}

