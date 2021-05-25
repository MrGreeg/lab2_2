#pragma once
#include "TypeInfo.h"

// базова€ €чейка
class BaseCell
{
private:
	unsigned int x;
	unsigned int y;
public:


	BaseCell() : x(0), y(0) {};
	BaseCell(unsigned int x, unsigned int y): x(x), y(y) {};

	virtual int GetType() { return TypeBaseCell; };
};

