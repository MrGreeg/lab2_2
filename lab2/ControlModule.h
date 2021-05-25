#pragma once
#include "BaseModule.h"
#include "ModularPlatform.h"

class ControlModule :
    public BaseModule
{
private:
    unsigned int radius;                // радиус действия
    unsigned int maximumNumberDevices;  // максимальное количество устройств
    ModularPlatform** ModularcontrolledModularsPlatforms;    // контролируемые модули

public:
    ControlModule() : BaseModule(), radius(0), maximumNumberDevices(0) { ModularcontrolledModularsPlatforms = nullptr; };
    ControlModule(bool state, unsigned int cost, unsigned int powerConsumptionLevel, unsigned int priority, unsigned int radius, unsigned int maximumNumberDevices) :
        BaseModule(powerConsumptionLevel, state, priority, cost), radius(radius), maximumNumberDevices(maximumNumberDevices) {
        ModularcontrolledModularsPlatforms = new ModularPlatform * [maximumNumberDevices];
        for (int i = 0; i < maximumNumberDevices; i++) {
            ModularcontrolledModularsPlatforms[i] = new ModularPlatform();
        }
    };
    ~ControlModule() {
        for (int i = 0; i < maximumNumberDevices; i++) {
            delete ModularcontrolledModularsPlatforms[i];
        }
        delete[] ModularcontrolledModularsPlatforms;
    };
    BaseCell* NewManagementResource(ModularPlatform *platform) {
        int i = 0;
        while (i < maximumNumberDevices && ModularcontrolledModularsPlatforms[i]->GetType() != TypeModularPlatform) {
            i++;
        }
        if (i < maximumNumberDevices) {
            delete ModularcontrolledModularsPlatforms[i];
            ModularcontrolledModularsPlatforms[i] = platform;
            return platform;
        }
        else
        {
            return nullptr;
        }
    };
    BaseCell* FreeManagementResource(ModularPlatform* platform) {
        int i = 0;
        while (i < maximumNumberDevices && ModularcontrolledModularsPlatforms[i]->GetType() != TypeModularPlatform) {
            i++;
        }
        if (i < maximumNumberDevices) {
            ModularcontrolledModularsPlatforms[i] = new ModularPlatform();
        }
        return nullptr;
    };
    int GetType() { return TypeControlModule; };
};

