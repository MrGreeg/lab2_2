#pragma once
#include "BaseCell.h"
class AI
{
private:
	BaseCell*** map;		// ���� ���������
	unsigned int size;

public:
	void SearchInterestPoint();
};

