#include "helper.h"

#include <iostream>
#include <limits>

void correct(int &checkNumber)
{
    while (!(std::cin >> checkNumber))
    {
        std::cout << "Введите корректное число: ";
        std::cin.clear();                                                   // Сброс ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Пропуск оставшегося ввода
    }
}
