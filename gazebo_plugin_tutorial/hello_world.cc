#include <gazebo/gazebo.hh> // Includes core set of basic gazebo functions

namespace gazebo // All plugins must use this namespace
{
  class WorldPluginTutorial : public WorldPlugin // Each plugin must inherit from a plugin type
  {
    public: WorldPluginTutorial() : WorldPlugin()
    {
      printf("Hello World!\n");
    }

    // receives SDF element
    public: void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
    {

    }
  };
  // Registered with macro, parameter is name of plugin class
  GZ_REGISTER_WORLD_PLUGIN(WorldPluginTutorial);
}
