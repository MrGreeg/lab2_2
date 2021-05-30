#pragma once
#include "BaseModule.h"

class ModularPlatform;
class EnvironmentDescriptor;

class SensorModule :
    public BaseModule
{
private:
    unsigned int radius;        // радиус действия
    unsigned char direction;    // направление
    unsigned int viewingAngle;  // угол обзора (не более 180)
    EnvironmentDescriptor *map;
    ModularPlatform* parent;
    
public:
    SensorModule() : BaseModule(), radius(0), direction(0), viewingAngle(0), map(nullptr), parent(nullptr) { };
    SensorModule(EnvironmentDescriptor* map, ModularPlatform* parent, bool state, unsigned int cost, unsigned int powerConsumptionLevel, unsigned int priority, unsigned int radius, unsigned int direction, unsigned int viewingAngle);
    
    EnvironmentDescriptor* GetInfoEnvironment() const;

    void SetDirection(unsigned int direction);

    unsigned int GetDirection();

    int GetType() const { return TypeSensorModule; };
};

