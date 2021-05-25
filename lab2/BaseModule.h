#pragma once
#include "TypeInfo.h"

// базовый модуль
class BaseModule
{
private:
	unsigned int powerConsumptionLevel;     // уровень энергопотребления
	bool state;								// состояние (включен/выключен)
	unsigned int priority;					// приоритет
	unsigned int cost;                      // стоимость

public:
	BaseModule() {
		powerConsumptionLevel = 0;
		state = true;
		priority = 0;
		cost = 0;
	}

	BaseModule(unsigned int powerConsumptionLevel, bool state, unsigned int priority, unsigned int cost) :
		powerConsumptionLevel(powerConsumptionLevel),
		state(state),
		priority(priority),
		cost(cost) {};


	void OnModule() {
		state = true;
	};
	void OffModule() {
		state = false;
	};
	
	// "Вернуть уровень энергопотребления или энергообеспечения"
	int EnergyLevel() {
		return powerConsumptionLevel;
	};

	int EnergySupplyLevel() { return 0; };
	
	virtual int GetType() { return TypeBaseModule; };

};

