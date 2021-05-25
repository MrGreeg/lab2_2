#pragma once
#include "ModularPlatform.h"
class MonitoringCenterPlatform :
    public ModularPlatform
{
    int GetType() { return TypeMonitoringCenterPlatform; };
};

