#include "ControlModule.h"
#include <algorithm>
#include "ModularPlatform.h"

ControlModule::ControlModule(ModularPlatform* parent, bool state, unsigned int cost, unsigned int powerConsumptionLevel, unsigned int priority, unsigned int radius, unsigned int maximumNumberDevices) :
    BaseModule(powerConsumptionLevel, state, priority, cost), radius(radius), maximumNumberDevices(maximumNumberDevices), parent(parent) {
    if (parent == nullptr) {
        throw "—сылка на управл€ющую платформу не может быть пустой!";
    }
    if (!(parent->GetType() == TypeControlMobilePlatform || parent->GetType() == TypeControlStaticPlatform)) {
        throw "”правл€ющий модуль устанавливаетс€ только на управл€ющую платформу";
    }

};
ControlModule::~ControlModule() {
    for (int i = 0; i < maximumNumberDevices; i++) {
        ModularcontrolledModularsPlatforms[i]->SetControle(nullptr);
        delete ModularcontrolledModularsPlatforms[i];
    }
};
ControlModule::ControlModule(const ControlModule& object) {	//  опирующий конструктор
    radius = object.radius;
    maximumNumberDevices = object.maximumNumberDevices;

    if (object.ModularcontrolledModularsPlatforms.size()) {
        for (int i = 0; i < object.ModularcontrolledModularsPlatforms.size(); i++) {
            ModularcontrolledModularsPlatforms.push_back(object.ModularcontrolledModularsPlatforms[i]);
        }
    }
};

ControlModule::ControlModule(ControlModule&& object) :                 // перемещающий конструктор
    radius(object.radius),
    maximumNumberDevices(object.maximumNumberDevices),
    ModularcontrolledModularsPlatforms(object.ModularcontrolledModularsPlatforms)
{
    object.radius = 0;
    object.maximumNumberDevices = 0;
    object.ModularcontrolledModularsPlatforms.clear();
}

ControlModule& ControlModule::operator=(const ControlModule& object) {     // копирующее присваивание
    if (this != &object) { // проверка  a = a
        for (int i = 0; i < ModularcontrolledModularsPlatforms.size(); i++) {
            delete ModularcontrolledModularsPlatforms[i];
        }
        ModularcontrolledModularsPlatforms.clear();
        radius = object.radius;
        maximumNumberDevices = object.maximumNumberDevices;

        for (int i = 0; i < object.ModularcontrolledModularsPlatforms.size(); i++) {
            ModularcontrolledModularsPlatforms.push_back(object.ModularcontrolledModularsPlatforms[i]);
        }
    }
    return *this;
};



ControlModule& ControlModule::operator = (ControlModule&& object) {          // перемещающее присваивание
    if (this != &object) { // проверка  a = a
        for (int i = 0; i < ModularcontrolledModularsPlatforms.size(); i++) {
            delete ModularcontrolledModularsPlatforms[i];
        }
        ModularcontrolledModularsPlatforms.clear();
        radius = object.radius;
        maximumNumberDevices = object.maximumNumberDevices;
        ModularcontrolledModularsPlatforms = object.ModularcontrolledModularsPlatforms;

        object.radius = 0;
        object.maximumNumberDevices = 0;
        object.ModularcontrolledModularsPlatforms.clear();
    }
    return *this;
};

void ControlModule::NewManagementResource(ModularPlatform* platform) {
    if (!isWork()) {
        throw "ћодуль отключен!";
    };
    if (parent == nullptr) {
        throw "ћодуль не установлен в управл€ющую платформу!";
    }
    if (ModularcontrolledModularsPlatforms.size() < maximumNumberDevices) {
        unsigned int x = parent->GetCoordX();
        unsigned int y = parent->GetCoordX();
        if (sqrt(pow(platform->GetCoordX() - x, 2) + pow(platform->GetCoordY() - y, 2)) < radius) {
            platform->SetControle(this);
            ModularcontrolledModularsPlatforms.push_back(platform);
        }
        else {
            throw "ѕлатформа слишком далеко.";
        }
    }
    else
    {
        throw "”же достигнут максимум подконтрольных устройств.";
    }
};

void ControlModule::FreeManagementResource(ModularPlatform* platform) {
    std::vector<ModularPlatform*>::iterator result = std::find(ModularcontrolledModularsPlatforms.begin(), ModularcontrolledModularsPlatforms.end(), platform);
    if (result == ModularcontrolledModularsPlatforms.end()) {
        throw "”казанна€ платформа не управл€етс€ данным модулем";
    }
    else
    {
        (*result)->SetControle(nullptr);
        ModularcontrolledModularsPlatforms.erase(result);
    }
};

