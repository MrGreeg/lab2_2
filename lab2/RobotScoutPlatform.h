#pragma once
#include "ModularPlatform.h"
class RobotScoutPlatform :
    public ModularPlatform
{
    int GetType() { return TypeRobotScoutPlatform; };
    void move(unsigned char direction, unsigned int count);
};

