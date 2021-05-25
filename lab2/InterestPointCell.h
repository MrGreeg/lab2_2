#pragma once
// точка интереса
#include "BaseCell.h"
class InterestPointCell :
    public BaseCell
{
private:
    int number;

public:
    InterestPointCell() :BaseCell(0, 0), number(0) {};
    InterestPointCell(unsigned int x, unsigned int y, int number_) : BaseCell(x, y) {
        number = number_;
    };
    int GetInfo() { return number; };
    int GetType() { return TypeInterestPointCell; };

};

