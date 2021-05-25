#pragma once
// модульна€ платформа
#include "BaseCell.h"
#include "BaseModule.h"
#include <string>

class ModularPlatform :
    public BaseCell
{
private:
    std::string description;                // строка описани€
    unsigned int powerConsumptionLevel;     // уровень энергопотреблени€
    unsigned int numberModules;             // количество слотов дл€ подключени€ модулей
    unsigned int cost;                      // стоимость
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
            throw "»ндекс слишком большой или модуль не установлен";
        }
    };

    void OffModule(unsigned int index) {
        if (index < numberModules && modules[index]->GetType() != TypeBaseModule) {
            modules[index]->OffModule();
        }
        else {
            throw "»ндекс слишком большой или модуль не установлен";
        }
    }

    void AddModule(unsigned int index, BaseModule* module) {
        if (index < numberModules && modules[index]->GetType() == TypeBaseModule) {
            if (this->GetType() == TypeControlMobilePlatform || this->GetType() == TypeControlStaticPlatform) {
                modules[index] == module;
            }
            else {
                throw "”правл€ющий модуль может быть установлен только на управл€ющую платформу!";
            }
        }
        else {
            throw "—лот уже содержит модуль или индекс слишком большой";
        }
    }

    void DelModule(unsigned int index) {
        if (index < numberModules && modules[index]->GetType() != TypeBaseModule) {
            delete modules[index];
            modules[index] = new BaseModule();
        }
        else {
            throw "—лот не содержит модуль или индекс слишком большой";
        }
    }

    ~ModularPlatform() {
        for (int i = 0; i < numberModules; i++) {
            delete modules[i];
        }
        delete[] modules;
    }
};

