#include "ControlStaticPlatform.h"
#include "RobotScoutPlatform.h"
#include "EnvironmentDescriptor.h"


EnvironmentDescriptor* ControlStaticPlatform::GetInfoEnviromentRobot(RobotScoutPlatform* robot)
{
    return robot->GetInfoEnvironment();
}

void ControlStaticPlatform::MoveRobot(RobotScoutPlatform* robot, unsigned int direction, unsigned int count)
{
    robot->move(direction, count);
}
