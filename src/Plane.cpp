#include "Plane.h"
#include "Ray.h"
#include <iostream>
bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  double t_temp;
  // t = (p-e)n/(dn)
  t_temp = ((point - ray.origin).dot(normal))/(ray.direction.dot(normal));
  if (t_temp < min_t){
    return false;
  }
  else{
    t = t_temp;
    n = normal.normalized();
    return true;
  }
  ////////////////////////////////////////////////////////////////////////////
}

