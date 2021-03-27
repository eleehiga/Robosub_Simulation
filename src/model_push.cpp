#include "model_push.h"

/**
 * Apply link forces to the frame model for the thruster.
 *
 * @return None.
 */
void ModelPush::addLinkForce()
{
  _frame->AddLinkForce(ignition::math::Vector3<double>(100.0, 0.0, 0.0), _link_ptr->RelativePose().Pos());
}
