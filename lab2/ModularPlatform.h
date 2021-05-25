#pragma once
// ��������� ���������
#include "BaseCell.h"
#include "BaseModule.h"
#include <string>

class ModularPlatform :
    public BaseCell
{
private:
    std::string description;                // ������ ��������
    unsigned int powerConsumptionLevel;     // ������� �����������������
    unsigned int numberModules;             // ���������� ������ ��� ����������� �������
    unsigned int cost;                      // ���������
    BaseModule** modules;

public:
    ModularPlatform() : description(""), powerConsumptionLevel(0), numberModules(0), cost(0) { modules = nullptr; };
    ModularPlatform(std::string description_, unsigned int powerConsumptionLevel_, unsigned int numberModules_, unsigned int cost_): 
        description(description_), powerConsumptionLevel(powerConsumptionLevel_), numberModules(numberModules_), cost(cost_) { 
        modules = new BaseModule * [numberModules];
        for (int i = 0; i < numberModules; i++) {
            modules[i] = new BaseModule();
        }
    };                     

    int GetType() { return TypeModularPlatform; };

    void OnModule(unsigned int index) {
        if (index < numberModules && modules[index]->GetType() != TypeBaseModule) {
            modules[index]->OnModule();
        }
        else {
            throw "������ ������� ������� ��� ������ �� ����������";
        }
    };

    void OffModule(unsigned int index) {
        if (index < numberModules && modules[index]->GetType() != TypeBaseModule) {
            modules[index]->OffModule();
        }
        else {
            throw "������ ������� ������� ��� ������ �� ����������";
        }
    }

    void AddModule(unsigned int index, BaseModule* module) {
        if (index < numberModules && modules[index]->GetType() == TypeBaseModule) {
            if (this->GetType() == TypeControlMobilePlatform || this->GetType() == TypeControlStaticPlatform) {
                modules[index] == module;
            }
            else {
                throw "����������� ������ ����� ���� ���������� ������ �� ����������� ���������!";
            }
        }
        else {
            throw "���� ��� �������� ������ ��� ������ ������� �������";
        }
    }

    void DelModule(unsigned int index) {
        if (index < numberModules && modules[index]->GetType() != TypeBaseModule) {
            delete modules[index];
            modules[index] = new BaseModule();
        }
        else {
            throw "���� �� �������� ������ ��� ������ ������� �������";
        }
    }

    ~ModularPlatform() {
        for (int i = 0; i < numberModules; i++) {
            delete modules[i];
        }
        delete[] modules;
    }
};

