#ifndef MODEL_PUSH_H
#define MODEL_PUSH_H

#include <string>

#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <gazebo/rendering/rendering.hh>
#include <ignition/math.hh>
#include <typeinfo>

#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <ros/advertise_options.h>
#include <std_msgs/String.h>

using std::string;
using namespace gazebo;

/**
 * model_push abstraction class.
 */
class ModelPush
{
public:
   /**
    * Constructor.
    *
    * @param name The name of the thruster.
    * @param link_ptr A pointer to the thruster link element.
    * @param parent The parent model pointer.
    */
    ModelPush(string name, physics::ModelPtr parent){
	_name = name;
	std::cout<<_name<<std::endl;
	_link_ptr = parent->GetLink(name);
        physics::Link_V links = parent->GetLinks();
	_frame = parent->GetLink("link");
    }
    ModelPush() {}
    ~ModelPush() {}

    void addLinkForce();

    string get_name();
    

    physics::LinkPtr get_LinkPtr();
    

    physics::LinkPtr get_Frame();
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
    string _name;

    /*
     * A link pointer to the thruster model element.
     */
    physics::LinkPtr _link_ptr;

    /*
     * A link pointer to the frame of the submarine. This pointer is used for
     * applying thruster forces to.
     */
//    physics::LinkPtr _frame;

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

#endif //MODEL_PUSH_H
