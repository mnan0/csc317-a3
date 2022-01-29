#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  bool object_check=false;
  bool hit_check = false;
  double t_param;
  Eigen::Vector3d n_param;
  double first_visible_hit = 0.0;
  for (int i=0;i< objects.size();i++){
    object_check = (*(objects.at(i).get())).intersect(ray, min_t, t_param,n_param);
    //printf("%d",object_check);
    if (object_check==true){
      hit_check = true;
      if (first_visible_hit==0.0){
        first_visible_hit = t_param;
        hit_id = i;
        n = n_param;
      }
      else{
        if (t_param < first_visible_hit){
          first_visible_hit = t_param;
          hit_id =i;
          n = n_param;
        }
      }


    }
  }
  if (hit_check==true){
    t = first_visible_hit;
    //printf("reached\n");
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
