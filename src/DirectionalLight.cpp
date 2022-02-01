#include "DirectionalLight.h"
#include <limits>
#include <stdio.h>
void DirectionalLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
  ////////////////////////////////////////////////////////////////////////////
  max_t = std::numeric_limits<double>::infinity();
  d = (q+(-1)*(this->d)-q).normalized();
  //printf("Query point: %f %f %f\n",q(0),q(1),q(2));
  //printf("New direction vector: %f %f %f\n",d(0),d(1),d(2));
  ////////////////////////////////////////////////////////////////////////////
}

