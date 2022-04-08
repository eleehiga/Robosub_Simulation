#include "model_push.h"
#include <ros/ros.h>
#include <ros/subscribe_options.h>
#include <sensor_msgs/JointState.h>
#include <math.h>
#include <ros/ros.h>
#include <ros/subscribe_options.h>
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>
#include <sensor_msgs/JointState.h>

/**
 * Apply link forces to the frame model for the thruster.
 *
 * @return None.
 */
void ModelPush::addLinkForce()
{
  std::cout<<"-------------------FORCE BEING ADDED-----------------------"<<std::endl;
  _link_ptr->AddLinkForce(ignition::math::Vector3<double>(10, -10, 10), _link_ptr->RelativePose().Pos());
  std::cout<<"-------------------FORCE ADDED-----------------------"<<std::endl;
}

void ModelPush::addSubscribeForce()
{
	// ros::init("talker");

	ros::NodeHandle* rosnode = new ros::NodeHandle();
	ros::SubscribeOptions jointStatesSo = ros::SubscribeOptions::create<sensor_msgs::JointState>("/test", 1, SetJointStates,ros::VoidPtr(), rosnode->getCallbackQueue());
	ros::Subscriber subJointState = rosnode->subscribe(jointStatesSo);
	ros::spin();
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

void ModelPush::SetJointStates(const sensor_msgs::JointState::ConstPtr &_js)
{
  static ros::Time startTime = ros::Time::now();
  {
    std::cout<<"AYo"<<std::endl;
  }
}
