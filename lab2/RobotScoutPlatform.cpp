#include "RobotScoutPlatform.h"
#include "EnvironmentDescriptor.h"

void RobotScoutPlatform::move(unsigned char direction, unsigned int count)
{
	if (GetControle() == nullptr) {
		throw "Модуль не управляется";
	}
	unsigned int new_x, new_y, x, y;
	unsigned int passed = 0;	// сколько пройдено
	bool possible = true;		// возможно ли перемещение

	x = GetCoordX();
	y = GetCoordY();

	switch (direction)
	{
	North:
		while (possible && passed < count)
		{
			new_x = x;
			new_y = y - 1;
			if (map->GetCell(new_x, new_y)->GetType() != TypeBaseCell) {
				possible = false;
			}
			else {
				map->SetCell(new_x, new_y, this);
				map->SetCell(x, y, new BaseCell(x, y));
				SetCoord(new_x, new_y);
				passed++;
				x = new_x;
				y = new_y;
			}
		}
		break;
	West:
		while (possible && passed < count)
		{
			new_x = x + 1;
			new_y = y;
			if (map->GetCell(new_x, new_y)->GetType() != TypeBaseCell) {
				possible = false;
			}
			else {
				map->SetCell(new_x, new_y, this);
				map->SetCell(x, y, new BaseCell(x, y));
				SetCoord(new_x, new_y);
				passed++;
				x = new_x;
				y = new_y;
			}
		}
		break;
	South:
		while (possible && passed < count)
		{
			new_x = x;
			new_y = y + 1;
			if (map->GetCell(new_x, new_y)->GetType() != TypeBaseCell) {
				possible = false;
			}
			else {
				map->SetCell(new_x, new_y, this);
				map->SetCell(x, y, new BaseCell(x, y));
				SetCoord(new_x, new_y);
				passed++;
				x = new_x;
				y = new_y;
			}
		}
		break;
	East:
		while (possible && passed < count)
		{
			new_x = x - 1;
			new_y = y;
			if (map->GetCell(new_x, new_y)->GetType() != TypeBaseCell) {
				possible = false;
			}
			else {
				map->SetCell(new_x, new_y, this);
				map->SetCell(x, y, new BaseCell(x, y));
				SetCoord(new_x, new_y);
				passed++;
				x = new_x;
				y = new_y;
			}
		}
		break;
	default:
		throw "Некорректное направление";
	}
	SetDirection(direction);
}
