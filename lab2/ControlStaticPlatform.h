#pragma once
#include "StaticModularPlatform.h"
class ControlStaticPlatform :
    public StaticModularPlatform
{
public:

    int GetType() {
        return TypeControlStaticPlatform;
    }

    BaseCell* GetInfoEnviromentRobot();

    void MoveRobot() {
        
    };
};

