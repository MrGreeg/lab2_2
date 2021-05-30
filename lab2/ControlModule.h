#pragma once
#include "BaseModule.h"
#include "vector"

class ModularPlatform;

class ControlModule :
    public BaseModule
{
private:
    unsigned int radius;                // ������ ��������
    unsigned int maximumNumberDevices;  // ������������ ���������� ���������
    ModularPlatform *parent;
    std::vector<ModularPlatform*> ModularcontrolledModularsPlatforms;    // �������������� ��������� ���������

public:
    ControlModule() : BaseModule(), radius(0), maximumNumberDevices(0), parent(nullptr) { };
    
    ControlModule(ModularPlatform* parent, bool state, unsigned int cost, unsigned int powerConsumptionLevel, unsigned int priority, unsigned int radius, unsigned int maximumNumberDevices);

    ~ControlModule();

    ControlModule(const ControlModule& object);

    ControlModule(ControlModule&& object);

    ControlModule& operator = (const ControlModule& object);

    ControlModule& operator=(ControlModule&& object);

    void NewManagementResource(ModularPlatform* platform);

    void FreeManagementResource(ModularPlatform* platform);

    std::vector<ModularPlatform*> GetModularPlatform() { return ModularcontrolledModularsPlatforms; };

    int GetType() { return TypeControlModule; };
};

