#include "Sphere.h"
#include "Ray.h"

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // note (s-e) is just the direction vector of the ray!
  // a = (s-e)^T * (s-e)
  // b = 2 * (e-c) * (s-e)
  // c = (e-c) * (e-c) - r^2

  // STEP 1: use determinant of quadratic eqn to follow by cases
  double a = ray.direction.dot(ray.direction);
  double b = 2.0 * ray.direction.dot(ray.origin - center);
  double c = (ray.origin - center).dot(ray.origin - center) - radius*radius;
  double t_temp;
  double t_temp_two;
  // STEP 2: calculate determinant, proceed by cases 
  double determinant = b*b - 4*a*c;

  if (determinant < 0){
    // negative: no intersection
    return false;
  }
  else if (determinant ==0 ){
    // zero : ray grazes sphere at one point
    t_temp = -1.0 * b * 0.5 * a;
    if (t_temp < min_t){
      return false;
    }
    t = t_temp;
    Eigen::Vector3d point = ray.origin + (ray.direction * t);
    n = (point - center)/radius;
    return true;
  }
  else{
    // positive: ray intersects at two points on sphere
    t_temp = (-1.0 * b + sqrt(determinant))/(2.0 * a);
    t_temp_two = (-1.0 * b - sqrt(determinant))/(2.0 * a);
    if (t_temp < t_temp_two && t_temp >= min_t){
      t = t_temp;
      
    }
    else if (t_temp_two >= min_t){
      t=t_temp_two;
    }
    Eigen::Vector3d point = ray.origin + (ray.direction * t);
    n = (point - center)/radius;
    return true;
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}

