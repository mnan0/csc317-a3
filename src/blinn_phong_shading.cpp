#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>
#include <limits>
#include <stdio.h>
Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d Ia = {0.1,0.1,0.1};
  Object * contact = (objects.at(hit_id).get());
  std::vector<std::shared_ptr<Object> > objects_copy;
  Material m = *(*contact).material;
  Eigen::Vector3d ambient = (Ia.array() * m.ka.array()).matrix();
  Eigen::Vector3d diffuse; diffuse << 0.0, 0.0, 0.0;
  Eigen::Vector3d specular; specular << 0.0, 0.0, 0.0;
  int hit_temp;
  double t_temp;
  Eigen::Vector3d n_temp;
  Eigen::Vector3d intersection_point = ray.origin + t*(ray.direction);
  Ray light_ray;
  light_ray.origin = intersection_point;
  double max_t;
  Eigen::Vector3d return_direction;
  Eigen::Vector3d half;
  for (int i=0; i < lights.size(); i++){
    
    // get direction of ray from hit point to light
    (*(lights.at(i).get())).direction(light_ray.origin,return_direction,max_t);
    light_ray.direction = return_direction;
    objects_copy = objects;
    objects_copy.erase(objects_copy.begin() + hit_id);
    // use first hit for shadows?? if found, then don't add spec and diffuse?
    if (first_hit(light_ray,sqrt(std::numeric_limits<double>::epsilon()) ,objects_copy,hit_temp,t_temp,n_temp) && t_temp < max_t){
      //printf("%d",t_temp < max_t);
      continue;
    }
    else{
      diffuse += std::max(0.0,n.dot(light_ray.direction)) * ((*(lights.at(i).get())).I.array() * m.kd.array()).matrix();
      
      // calculate half vector
      // treat ray as v
      half = ((-1.0)*(ray.direction.normalized()) + light_ray.direction).normalized();
      specular += pow(std::max(0.0,n.dot(half)),m.phong_exponent) * ((*(lights.at(i).get())).I.array() * m.ks.array()).matrix();
    }
  }
  return ambient + specular + diffuse;
  ////////////////////////////////////////////////////////////////////////////
}
