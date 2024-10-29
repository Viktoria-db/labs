#include <iostream>

int main()
{
    int A=0;
    int B=0;
    int C=0;
    std::cout << "Введите натуральные числа A, B и C: ";
    std::cin >> A >> B >> C;

    if (A < 1 || B < 1 || C < 1)
    {
        std::cout << "Ошибка: Вводить нужно натуральные числа." << std::endl;
    }
    else if (A > B && B > C) {
        std::cout << "A - B - C = " << A - B - C << std::endl;
    } else if (B > A && B % C == 0) {
        std::cout << "B / C + B - A = " << B / C + B - A << std::endl;
    } else {
        std::cout << "A + B + C = " << A + B + C << std::endl;
    }


    int N=0;
    std::cout << "Введите номер ошибки: ";
    std::cin >> N;

    switch (N)
    {
        case 0:
            std::cout << "Все хорошо" << std::endl;
            break;
        case 1:
            std::cout << "Ошибка чтения файла" << std::endl;
            break;
        case 2:
            std::cout << "Ошибка записи файла" << std::endl;
            break;
        case 3:
            std::cout << "Не все поля определены" << std::endl;
            break;
        default:
            std::cout << "Неверный номер ошибки" << std::endl;
            break;
    }


    int x=0;
    std::cout << "Введите x (-1 либо 1): ";
    std::cin >> x;

    if (x == -1) {
        std::cout << "Negative number" << std::endl;
    } else if (x == 1) {
        std::cout << "Positive number" << std::endl;
    } else {
        std::cout << "Ошибка: Введено неверное число" << std::endl;
    }

    return 0;
}