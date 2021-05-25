#pragma once
#include "BaseCell.h"
class ObstacleCell :
    public BaseCell
{
    int GetType() { return TypeObstacleCell; };
};

