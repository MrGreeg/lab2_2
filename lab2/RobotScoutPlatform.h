#pragma once
#include "ModularPlatform.h"
#include "SensorModule.h"

class EnvironmentDescriptor;

class RobotScoutPlatform :
    public ModularPlatform, public SensorModule
{
private:
    EnvironmentDescriptor* map;

public:
    RobotScoutPlatform(EnvironmentDescriptor* map, unsigned int direction, unsigned int x, unsigned int y, std::string description_, unsigned int powerConsumptionLevel_, unsigned int maxCountModules_, unsigned int cost_) :
        ModularPlatform(x, y, description_, powerConsumptionLevel_, maxCountModules_, cost_), SensorModule(map, this, true, 0, 0, 0, 15, direction, 180), map(map) {};
    int GetType() { return TypeRobotScoutPlatform; };
    void move(unsigned char direction, unsigned int count);
};

