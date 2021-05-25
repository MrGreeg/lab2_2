// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "EnvironmentDescriptor.h"
#include "ControlStaticPlatform.h"
#include "InterestPointCell.h"
#include "BaseCell.h"
#include <typeinfo>

int randInt(const int from, const int to) {
    if (to == from)
        return to;
    if (to < from)
        return randInt(to, from);
    return from + rand() % (to - from + 1);
}

int main()
{
    BaseCell *a = new BaseCell();
    const int size = 10;
    //std::cout << "Hello World!\n";
    EnvironmentDescriptor mainEnvironment(size);
    for (int i = 0; i < 15; i++) {
        int x = randInt(0, size-1);
        int y = randInt(0, size - 1);
        mainEnvironment.SetCell(x, y, new InterestPointCell(x, y, i));
    }
    
    mainEnvironment.print();

    mainEnvironment.SetSize(15);

    mainEnvironment.print();

    mainEnvironment.SetSize(10);

    mainEnvironment.print();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
