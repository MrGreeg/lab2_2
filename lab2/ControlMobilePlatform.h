#pragma once
#include "MobileModularPlatform.h"

class EnvironmentDescriptor;
class RobotScoutPlatform;

class RobotScoutPlatform;

class ControlMobilePlatform :
    public MobileModularPlatform
{

public:
    int GetType() { return TypeControlMobilePlatform; };
    EnvironmentDescriptor* GetInfoEnviromentRobot(RobotScoutPlatform *robot);
    void MoveRobot(RobotScoutPlatform* robot, unsigned int direction, unsigned int count);
};

