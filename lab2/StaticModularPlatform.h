#pragma once
#include "ModularPlatform.h"
class StaticModularPlatform :
    public ModularPlatform
{
    int GetType() { return TypeStaticModularPlatform; };
};

