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

	virtual int GetType() const { return TypeBaseCell; };
	
	unsigned int GetCoordX() const {
		return x;
	}

	unsigned int GetCoordY() const {
		return y;
	}

	void SetCoord(unsigned int x, unsigned int y) {
		BaseCell::x = x;
		BaseCell::y = y;
	}
};

