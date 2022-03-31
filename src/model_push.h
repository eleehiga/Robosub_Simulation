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
#include <sensor_msgs/JointState.h>
#include <math.h>
#include <ros/ros.h>
#include <ros/subscribe_options.h>
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>
#include <sensor_msgs/JointState.h>

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
	std::cout<<"---------------------NAME BEING INTIALIZED-------------------------"<<std::endl;
	_name = name;
	ROS_INFO("_name is ");
	std::cout<<_name<<std::endl;
	ROS_INFO("name is ");
	std::cout<<name<<std::endl;
	std::cout<<"---------------------NAME INTIALIZED-------------------------"<<std::endl;
	std::cout<<"---------------------_link_ptr BEING INTIALIZED-------------------------"<<std::endl;
	_link_ptr = parent->GetLink(name);
	std::cout<<"---------------------_link_ptr INTIALIZED-------------------------"<<std::endl;
	std::cout<<"_link_ptr is: "<<_link_ptr<<std::endl;
	std::cout<<"---------------------_frame BEING INTIALIZED-------------------------"<<std::endl;
	std::cout<<"????????????????????????????????????????"<<std::endl;
        physics::Link_V links = parent->GetLinks();
	std::cout<<"????????????????????????????????????????"<<std::endl;
        std::cout<<"PRINTING LINKS"<<std::endl;
	std::cout<<"????????????????????????????????????????"<<std::endl;
        for(auto const& link : links)
          std::cout<<link->GetName()<<std::endl;
	std::cout<<"????????????????????????????????????????"<<std::endl;
	_frame = parent->GetLink("link");
	std::cout<<"????????????????????????????????????????"<<std::endl;
	std::cout<<"---------------------_frame INTIALIZED-------------------------"<<std::endl;
	std::cout<<"_frame is: "<<_frame<<std::endl;
    }
    ModelPush() {}
    ~ModelPush() {}

    void addLinkForce();
    void addSubscribeForce();
    static void SetJointStates(const sensor_msgs::JointState::ConstPtr);

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

#endif //MODEL_PUSH_H
