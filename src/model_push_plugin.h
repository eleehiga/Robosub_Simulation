#ifndef MODEL_PUSH_PLUGIN_H
#define MODEL_PUSH_PLUGIN_H

#include <boost/bind.hpp>

#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/rendering/rendering.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/common/common.hh>
#include <ignition/math.hh>

#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <ros/advertise_options.h>
#include <std_msgs/String.h>

#include "model_push.h"

#include <iostream>
#include <vector>
#include <string>


namespace gazebo
{
/**
 * ModelPushPlugin for Gazebo.
 */
class ModelPushPlugin : public ModelPlugin
{
public:
    ModelPushPlugin() {}
    ~ModelPushPlugin() {}
    void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf);
    virtual void Update();

private:
    // gazebo plugin objects
    event::ConnectionPtr updateConnection;

    // ModelPush objects
    ModelPush modelPush;

    // gazebo messaging objects
    transport::PublisherPtr vis_pub;
    transport::NodePtr node;
    ros::Time last_update_time;

    void UpdateModelPush();
};
}
#endif //MODEL_PUSH_PLUGIN_H
