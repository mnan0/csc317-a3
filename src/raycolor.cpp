#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"
// #include <stdio.h>
bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  rgb = Eigen::Vector3d(0,0,0);
  int hit=0;
  Eigen::Vector3d n_temp;
  double t_temp = 0.0;
  Ray new_ray;
  Eigen::Vector3d new_rgb;
  Object * intersect_pt;
  Material m;

  if (first_hit(ray,min_t,objects,hit,t_temp,n_temp)){
    // checks for t_temp >= min_t are handled in intersect functions
    rgb += blinn_phong_shading(ray,hit,t_temp,n_temp,objects,lights);
    if (num_recursive_calls!=0){
      // do a recursive reflection ray on num_recursive_calls --
      new_ray.direction = reflect(ray.direction.normalized(),n_temp);
      new_ray.origin = ray.origin + (t_temp) * ray.direction;
      
      if (raycolor(new_ray,sqrt(std::numeric_limits<double>::epsilon()),objects,lights,num_recursive_calls - 1,new_rgb)){
        intersect_pt = objects.at(hit).get();
        m = *(*intersect_pt).material;
        rgb += (m.km.array() * new_rgb.array()).matrix();
      }
    }
    return true;
  }
  else{
    return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}
