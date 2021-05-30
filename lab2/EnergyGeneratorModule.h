#pragma once
#include "BaseModule.h"
class EnergyGeneratorModule :
    public BaseModule
{
private:
    unsigned int energySupplyLevel;     // ������� �����������������
public:
    EnergyGeneratorModule() : BaseModule(), energySupplyLevel(0) { };
    EnergyGeneratorModule(bool state, unsigned int cost, unsigned int energySupplyLevel) :
        BaseModule(0, state, 0, cost), energySupplyLevel(energySupplyLevel) {};

    int GetType() const { return TypeEnergyGeneratorModule; };
    int GetEnergySupplyLevel() const { return energySupplyLevel; }
};

