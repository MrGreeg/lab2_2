#pragma once
#include "MobileModularPlatform.h"
class ControlMobilePlatform :
    public MobileModularPlatform
{

public:
    int GetType() { return TypeControlMobilePlatform; };
    BaseCell* GetInfoEnviromentRobot();
    void MoveRobot();
};

