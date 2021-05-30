#pragma once
#include "BaseCell.h"
#include <iomanip>
#include <iostream>

//  ласс описатель среды
class EnvironmentDescriptor
{
private:
	BaseCell*** map;		// план местности
	unsigned int size;

public:
	EnvironmentDescriptor() : map(nullptr), size(0) {};
	EnvironmentDescriptor(unsigned int size) {
		EnvironmentDescriptor::size = size;
		map = new BaseCell ** [size];
		for (int i = 0; i < size; i++) {
			map[i] = new BaseCell * [size];
			for (int j = 0; j < size; j++) {
				map[i][j] = new BaseCell(i, j);
			}
		}
	}

	BaseCell* GetCell(unsigned int x, unsigned int y) const {
		if (x > size || y > size) {
			throw "x or y exceed the maximum value";
		}
		else {
			return map[x][y];
		}
	}
	unsigned int GetSize() const {
		return size;
	};

	unsigned int SetSize(unsigned int newSize) {
		if (size < newSize) {
			// выдел€ю новый участок пам€ти
			BaseCell*** tempMap = new BaseCell ** [newSize];
			for (int i = 0; i < newSize; i++) {
				tempMap[i] = new BaseCell*[newSize];
			}

			// копирую уже существующую карту и сразу особождаю пам€ть
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					tempMap[i][j] = map[i][j];
				}
				for (int j = size; j < newSize; j++) {
					tempMap[i][j] = new BaseCell(i, j);
				}
				delete[] map[i];
			}
			delete[] map;
			for (int i = size; i < newSize; i++) {
				for (int j = 0; j < newSize; j++) {
					tempMap[i][j] = new BaseCell(i, j);
				}
			}

			map = tempMap;
		}
		else if (newSize == 0) {
			// освобождаю всю выделенную пам€ть
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					delete map[i][j];
				}
				delete[] map[i];
			}
			delete[] map;
		}
		else if (size > newSize) {
			for (int i = newSize; i < size; i++) {
				for (int j = 0; j < size; j++) {
					delete map[i][j];
				}
				delete[] map[i];
			}
		}
		size = newSize;
		return size;
	};

	int GetTypeCell(unsigned int x, unsigned int y) {
		if (x > size || y > size) {
			throw "x or y exceed the maximum value";
		}
		else {
			return map[x][y]->GetType();
		}
	}

	void SetCell(unsigned int x, unsigned int y, BaseCell* cell) {
		if (x > size || y > size) {
			throw "x or y exceed the maximum value";
		}
		else {
			delete map[x][y];
			map[x][y] = cell;
		}
	}

	void print() {
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				std::cout << std::setw(3) << map[x][y]->GetType();
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;		
	}


};

