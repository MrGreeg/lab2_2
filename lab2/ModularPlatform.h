#pragma once
// ��������� ���������
#include "BaseCell.h"
#include "BaseModule.h"
#include <string>
#include "vector"
#include "ControlModule.h"

class ModularPlatform :
    public BaseCell
{
private:
    std::string description;                // ������ ��������
    unsigned int powerConsumptionLevel;     // ������� �����������������
    unsigned int maxCountModules;           // ���������� ������ ��� ����������� �������
    unsigned int cost;                      // ���������
    ControlModule* controlModule;           // ��������� �� ����������� ������
    std::vector<BaseModule*> modules;

public:
    ModularPlatform() : BaseCell(), description(""), powerConsumptionLevel(0), maxCountModules(0), cost(0), controlModule(nullptr) {};
    ModularPlatform(unsigned int x, unsigned int y, std::string description_, unsigned int powerConsumptionLevel_, unsigned int maxCountModules_, unsigned int cost_):
        BaseCell(x, y),
        description(description_), 
        powerConsumptionLevel(powerConsumptionLevel_), 
        maxCountModules(maxCountModules_),
        cost(cost_), controlModule(controlModule) {
    };                     

    int GetType() const { return TypeModularPlatform; };

    void SetControle(ControlModule* controlModule) {
        ModularPlatform::controlModule = controlModule;
    };

    ControlModule* GetControle() { return controlModule; }

    void OnModule(unsigned int index) {
        if (index < modules.size()) {
            modules[index]->OnModule();
        }
        else {
            throw "������ ������� ������� ��� ������ �� ����������";
        }
    };

    void OffModule(unsigned int index) {
        if (index < modules.size()) {
            modules[index]->OffModule();
        }
        else {
            throw "������ ������� ������� ��� ������ �� ����������";
        }
    }

    void AddModule(BaseModule* module) {
        if (modules.size() < maxCountModules) {
            if (this->GetType() == TypeControlMobilePlatform || this->GetType() == TypeControlStaticPlatform) {
                modules.push_back(module);
            }
            else {
                throw "����������� ������ ����� ���� ���������� ������ �� ����������� ���������!";
            }
        }
        else {
            throw "����������� ��������� ����";
        }
    }

    void DelModule(unsigned int index) {
        if (index < modules.size()) {
            delete modules[index];
            modules.erase(modules.begin() + index);
        }
        else {
            throw "������ ������� �������";
        }
    }

    ~ModularPlatform() {
        for (int i = 0; i < modules.size(); i++) {
            delete modules[i];
        }
        modules.clear();
    }

    ModularPlatform(const ModularPlatform& object) {	// ���������� �����������
        description = object.description;                // ������ ��������
        powerConsumptionLevel = object.powerConsumptionLevel;     // ������� �����������������
        maxCountModules = object.maxCountModules;             // ���������� ������ ��� ����������� �������
        cost = object.cost;                      // ���������
        controlModule = object.controlModule;

        if (object.modules.size()) {
            for (int i = 0; i < object.modules.size(); i++) {
                modules.push_back(object.modules[i]);
            }
        }
    };

    ModularPlatform(ModularPlatform&& object) :                 // ������������ �����������
        description(object.description),                        // ������ ��������
        powerConsumptionLevel(object.powerConsumptionLevel),    // ������� �����������������
        maxCountModules(object.maxCountModules),                // ���������� ������ ��� ����������� �������
        cost(object.cost),
        modules(object.modules),
        controlModule(object.controlModule)
    {
        object.description = "";
        object.powerConsumptionLevel = 0;
        object.maxCountModules = 0;
        object.cost = 0;
        controlModule = nullptr;
        object.modules.clear();
    };

    ModularPlatform& operator = (const ModularPlatform& object) {     // ���������� ������������
        if (this != &object) { // ��������  a = a
            for (int i = 0; i < modules.size(); i++) {
                delete modules[i];
            }
            modules.clear();
            description = object.description;                // ������ ��������
            powerConsumptionLevel = object.powerConsumptionLevel;     // ������� �����������������
            maxCountModules = object.maxCountModules;             // ���������� ������ ��� ����������� �������
            cost = object.cost;                      // ���������
            controlModule = object.controlModule;
            for (int i = 0; i < object.modules.size(); i++) {
                modules.push_back(object.modules[i]);
            }
        }
        return *this;
    };

    ModularPlatform& operator = (ModularPlatform&& object) {          // ������������ ������������
        if (this != &object) { // ��������  a = a
            for (int i = 0; i < modules.size(); i++) {
                delete modules[i];
            }
            modules.clear();
            description = object.description;                // ������ ��������
            powerConsumptionLevel = object.powerConsumptionLevel;     // ������� �����������������
            maxCountModules = object.maxCountModules;             // ���������� ������ ��� ����������� �������
            cost = object.cost;                      // ���������
            modules = object.modules;
            controlModule = object.controlModule;

            object.description = "";
            object.powerConsumptionLevel = 0;
            object.maxCountModules = 0;
            object.cost = 0;
            object.controlModule = nullptr;
            object.modules.clear();
        }
        return *this;
    };

    
};

