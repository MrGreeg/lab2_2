#pragma once
#include "ModularPlatform.h"
class MobileModularPlatform :
    public ModularPlatform
{
private:
    unsigned int speed;     // ��������

public:
    int GetType() { return TypeMobileModularPlatform; };
    void move(unsigned char direction, unsigned int count);
};

