#pragma once
#include "ModularPlatform.h"
class StaticModularPlatform :
    public ModularPlatform
{
public:
    int GetType() { return TypeStaticModularPlatform; };
};

