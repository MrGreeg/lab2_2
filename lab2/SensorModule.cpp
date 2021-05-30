#include "SensorModule.h"
#include "ModularPlatform.h"
#include "EnvironmentDescriptor.h"

SensorModule::SensorModule(EnvironmentDescriptor* map, ModularPlatform* parent, bool state, unsigned int cost, unsigned int powerConsumptionLevel, unsigned int priority, unsigned int radius, unsigned int direction, unsigned int viewingAngle) :
    BaseModule(powerConsumptionLevel, state, priority, cost), direction(direction), map(map), parent(parent) {
    if (viewingAngle == 180) {
        SensorModule::viewingAngle = viewingAngle;
    }
    else {
        SensorModule::viewingAngle = viewingAngle % 180;
    }

    if (radius > map->GetSize()) {
        SensorModule::radius = map->GetSize();
    }
    else {
        SensorModule::radius = radius;
    }
    if (direction == North || direction == West || direction == South || direction == East) {
        SensorModule::direction = direction;
    }
    else {
        SensorModule::direction = North;
    }
}
EnvironmentDescriptor* SensorModule::GetInfoEnvironment() const {
    if (!isWork()) {
        throw "Модуль отключен!";
    };
    if (parent == nullptr) {
        throw "Модуль не установлен в управляющую платформу!";
    }
    EnvironmentDescriptor* newMap = new EnvironmentDescriptor(radius * 2);
    unsigned int x = parent->GetCoordX();
    unsigned int y = parent->GetCoordY();
    unsigned int x_ = 0;
    unsigned int y_ = 0;
    for (int i = std::max(x - radius, (unsigned int)0); i < std::min(x + radius, map->GetSize()); i++) {
        for (int j = std::max(y - radius, (unsigned int)0); j < std::min(y + radius, map->GetSize()); j++) {
            if (sqrt(pow(i - x, 2) + pow(j - y, 2)) < radius) {
                newMap->SetCell(x_, y_, map->GetCell(i, j));
            }
            else {
                newMap->GetCell(x_, y_)->SetCoord(x_, y_);
            }
            y_++;
        }
        x_++;
    }
    return newMap;
};

void SensorModule::SetDirection(unsigned int direction) {
    if (direction == North || direction == West || direction == South || direction == East) {
        SensorModule::direction = direction;
    }
}

unsigned int SensorModule::GetDirection() {
    return direction;
}

