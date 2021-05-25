#pragma once
#include "BaseModule.h"
#include "BaseCell.h"
class SensorModule :
    public BaseModule
{
private:
    unsigned int radius;        // радиус действия
    unsigned char direction;    // направление
    unsigned int viewingAngle;  // угол обзора
    BaseCell ***map;
    
public:
    SensorModule() : BaseModule(), radius(0), direction(0), viewingAngle(0), map(nullptr) { };
    SensorModule(BaseCell ***map, bool state, unsigned int cost, unsigned int powerConsumptionLevel, unsigned int priority, unsigned int radius, unsigned int direction, unsigned int viewingAngle) :
        BaseModule(powerConsumptionLevel, state, priority, cost), direction(direction), radius(radius), viewingAngle(viewingAngle), map(map) {};
    BaseCell* GetInfoEnvironment() {
        return nullptr;
    };
    int GetType() { return TypeSensorModule; };
};

