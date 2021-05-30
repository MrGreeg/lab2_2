#pragma once

enum TypeInfo
{
	TypeBaseCell = -1,
	TypeModularPlatform,
	TypeObstacleCell,
	TypeInterestPointCell,
	TypeStaticModularPlatform,
	TypeMobileModularPlatform,
	TypeControlMobilePlatform,
	TypeControlStaticPlatform,
	TypeMonitoringCenterPlatform,
	TypeRobotScoutPlatform,
	TypeBaseModule,
	TypeControlModule,
	TypeSensorModule,
	TypeEnergyGeneratorModule
};

enum Direction
{
	North,			// направление север
	West,			// направление восток
	South,			// направление юг
	East			// направление запад
};