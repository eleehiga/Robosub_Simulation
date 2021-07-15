
Thruster::Thruster(const string name, physics::ModelPtr parent,
                   double max_force) :
    _current_force(0),
    _max_force(max_force),
    _name(name),
    _link_ptr(parent->GetLink(name)),
    _frame(parent->GetLink("frame")),
{}

void Thruster::addLinkForce()
{
   _current_force = _emulator.getThrusterForce(_name);
   ignition::math::Vector3<double> force(0, 0, 0);
   force.z = _current_force;
   force = _link_ptr->RelativePose().Rot() * force;
   _frame->AddLinkForce(force, _link_ptr->RelativePose().pos);
   //_link_ptr->AddLinkForce(ignition::math::Vector3<double>(1000.0, -400.0, 2443.0), _link_ptr->RelativePose().Pos());

}
