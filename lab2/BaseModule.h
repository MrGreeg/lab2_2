#pragma once
#include "TypeInfo.h"

// ������� ������
class BaseModule
{
private:
	unsigned int powerConsumptionLevel;     // ������� �����������������
	bool state;								// ��������� (�������/��������)
	unsigned int priority;					// ���������
	unsigned int cost;                      // ���������

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
	bool isWork() const {
		return state;
	}
	
	// "������� ������� ����������������� ��� �����������������"
	int GetEnergyLevel() const {
		return powerConsumptionLevel;
	};

	int GetEnergySupplyLevel() const { return 0; };
	
	virtual int GetType() const { return TypeBaseModule; };

};

