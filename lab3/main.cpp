#include <iostream>

int main()
{
    unsigned int x=0;
    int i=0;
    unsigned int bit=0;
    std::cout << "Введите число Х от 0 до 10^9: ";
    std::cin >> x;

    if (x <= 0 || x >= 1000000000)
    {
        std::cout << "Некорректное число.";
        return 1;
    }

    std::cout << "Введите номер бита i (начиная с 0): ";
    std::cin >> i;

    if (i < 0 || i >= 32)
    {
        std::cout << "Некооректное значение i.";
        return 1;
    }

    bit = (x >> i) & 1;
    std::cout << "i-ый бит равен: " << bit << std::endl;
}