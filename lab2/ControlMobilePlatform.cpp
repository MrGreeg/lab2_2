#include "ControlMobilePlatform.h"
#include "RobotScoutPlatform.h"
#include "EnvironmentDescriptor.h"


EnvironmentDescriptor* ControlMobilePlatform::GetInfoEnviromentRobot(RobotScoutPlatform* robot)
{
    return robot->GetInfoEnvironment();
}

void ControlMobilePlatform::MoveRobot(RobotScoutPlatform* robot, unsigned int direction, unsigned int count)
{
    robot->move(direction, count);
}
