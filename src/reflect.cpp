#include <Eigen/Core>

Eigen::Vector3d reflect(const Eigen::Vector3d & in, const Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d reflected;
  reflected = in - 2.0 * n.dot(in) * n;
  return reflected.normalized();
  ////////////////////////////////////////////////////////////////////////////
}
