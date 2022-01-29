#include "TriangleSoup.h"
#include "Triangle.h"
#include "first_hit.h"
bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  int id=0;
  bool intersection = first_hit(ray,min_t,triangles,id,t,n);
  return intersection;
  ////////////////////////////////////////////////////////////////////////////
}
