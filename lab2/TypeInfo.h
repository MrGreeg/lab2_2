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
	North,			// ����������� �����
	West,			// ����������� ������
	South,			// ����������� ��
	East			// ����������� �����
};