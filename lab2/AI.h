#pragma once
#include "BaseCell.h"
class AI
{
private:
	BaseCell*** map;		// план местности
	unsigned int size;

public:
	void SearchInterestPoint();
};

