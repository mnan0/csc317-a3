#include "PointLight.h"

void PointLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
  ////////////////////////////////////////////////////////////////////////////
  
  // remember to normalize the returned direction vector
  Eigen::Vector3d reg_direct = p - q;
  max_t = reg_direct.norm();
  d = reg_direct.normalized();
  ////////////////////////////////////////////////////////////////////////////
}
