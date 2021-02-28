#ifndef MODEL_PUSH_H
#define MODEL_PUSH_H

#include <string>

#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <gazebo/rendering/rendering.hh>
#include <ignition/math.hh>

using std::string;
using namespace gazebo;

/**
 * Thruster model abstraction class.
 */
class ModelPush
{
public:
    ModelPush(const string name, physics::ModelPtr parent);

    void addLinkForce();
  //  msgs::Visual getVisualizationMessage();

private:
    /*
     * The current force (in Newtons) exerted by the thruster.
     */
    /* Unnecessary
    double _current_force;
    */
    /*
     * The maximum force (in Newtons) that the thruster may exert in either
     * direction.
     */
    /* Unnecessary
    const double _max_force;
    */

    /*
     * The name of the thruster.
     */
    const string _name;

    /*
     * A link pointer to the thruster model element.
     */
    physics::LinkPtr _link_ptr;

    /*
     * A link pointer to the frame of the submarine. This pointer is used for
     * applying thruster forces to.
     */
    physics::LinkPtr _frame;

    /*
     * The thruster visualization message to visibly show how much force the
     * thrusters are exerting.
     */
    /* Unnecessary
    msgs::Visual _visualization_message;
    */

    /*
     * A reference to the emulator so that current thrust outputs can be
     * queried.
     */
    /* Unnecessary
    MaestroEmulator &_emulator;
    */

    /*
     * Z position of the surface of the water
     */
    /* Unnecessary
    const double _surface_z;
    */
};
#endif //THRUSTER_H
