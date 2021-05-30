#pragma once
#include "BaseCell.h"
class ObstacleCell :
    public BaseCell
{
private: 
    int number;

public:
    ObstacleCell() : BaseCell(), number(0) {};
    ObstacleCell(unsigned int x, unsigned int y, int number) : BaseCell(x, y), number(number) {};
    int GetType() const { return TypeObstacleCell; };
    int GetInfo() const { return number; };
};

