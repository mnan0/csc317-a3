#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  ray.origin = camera.e;
  // We know d is the vector from e to a particular pixel
  // The image rectangle is placed so the image center is directly in front of the "eye point" at a certain d
  double u = (-1.0 * camera.width * 0.5) + (camera.width/width)*(j+0.5);
  double v = ((-1.0 * camera.height * 0.5) + (camera.height/height)*(i+0.5))*-1.0;

  Eigen::Vector3d ray_direction;
  ray_direction = u*(camera.u) + v*(camera.v) + ((camera.d * -1.0) * camera.w);

  ray.direction = ray_direction;
  ////////////////////////////////////////////////////////////////////////////
}
