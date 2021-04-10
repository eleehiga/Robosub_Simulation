#include "model_push.h"

/**
 * Apply link forces to the frame model for the thruster.
 *
 * @return None.
 */
void ModelPush::addLinkForce()
{
  std::cout<<"-------------------FORCE BEING ADDED-----------------------"<<std::endl;
  _link_ptr->AddLinkForce(ignition::math::Vector3<double>(1000.0, -400.0, 2443.0), _link_ptr->RelativePose().Pos());
  std::cout<<"-------------------FORCE ADDED-----------------------"<<std::endl;
}

string ModelPush::get_name()
{
  return _name;
}

physics::LinkPtr ModelPush::get_LinkPtr()
{
  return _link_ptr;
}

physics::LinkPtr ModelPush::get_Frame()
{
  return _frame;
}
