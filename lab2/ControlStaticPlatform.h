#pragma once
#include "StaticModularPlatform.h"
class EnvironmentDescriptor;
class RobotScoutPlatform;

class ControlStaticPlatform :
    public StaticModularPlatform
{
public:

    int GetType() {
        return TypeControlStaticPlatform;
    }

    EnvironmentDescriptor* GetInfoEnviromentRobot(RobotScoutPlatform* robot);

    void MoveRobot(RobotScoutPlatform* robot, unsigned int direction, unsigned int count);

};

