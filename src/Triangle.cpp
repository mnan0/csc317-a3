#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Geometry>
#include <iostream>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  Eigen::Vector3d t1 = std::get<1>(corners) - std::get<0>(corners);
  Eigen::Vector3d t2 = std::get<2>(corners) - std::get<0>(corners);

  // e + td = a + alpha*(b-a) + beta*(c-a) 
  // (c-a) = t2, (b-a) = t1
  // e - a = [t1 t2 -d] [alpha beta t]^transpose

  Eigen::Vector3d b = ray.origin - std::get<0>(corners);
  Eigen::Matrix3d A;
  A.col(0) = t1;
  A.col(1) = t2;
  A.col(2) = -1.0 * ray.direction;

  Eigen::Vector3d sol = A.colPivHouseholderQr().solve(b);
  bool a_solution_exists = (A*sol).isApprox(b);
  if (a_solution_exists == true){
    // sol(0) == alpha
    // sol(1) == beta
    // sol(2) == t
    if (sol(0) >= 0 && sol(1) >= 0 && sol(0)+sol(1)<=1 && sol(2) >= min_t){
      t= sol(2);
      n = t1.cross(t2).normalized();
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}


