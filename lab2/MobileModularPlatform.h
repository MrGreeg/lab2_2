#pragma once
#include "ModularPlatform.h"

class EnvironmentDescriptor;

class MobileModularPlatform :
    public ModularPlatform
{
private:
    unsigned int speed;     // скорость
    EnvironmentDescriptor* map;

public:
    MobileModularPlatform(EnvironmentDescriptor* map, unsigned int speed, unsigned int x, unsigned int y, std::string description_, unsigned int powerConsumptionLevel_, unsigned int maxCountModules_, unsigned int cost_) :
        ModularPlatform(x, y, description_, powerConsumptionLevel_, maxCountModules_, cost_), speed(speed), map(map) {};

    int GetType() { return TypeMobileModularPlatform; };

    void move(unsigned char direction, unsigned int count);
};

