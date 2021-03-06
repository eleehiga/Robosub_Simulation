#include "model_push.h"

/**
 * Constructor.
 *
 * @param name The name of the thruster.
 * @param link_ptr A pointer to the thruster link element.
 * @param parent The parent model pointer.
 */
ModelPush::ModelPush(string name, physics::ModelPtr parent) {}

/**
 * Apply link forces to the frame model for the thruster.
 *
 * @return None.
 */
void ModelPush::addLinkForce()
{
  _frame->AddLinkForce(100, _link_ptr->GetRelativePose().pos);
}

