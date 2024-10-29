#include <iostream>
#include <cmath>

int main()
{
    int A=0;
    int B=0;
    int angle=0;
    float S=0;
    std::cout << "Введите сторону А: ";
    std::cin >> A;
    std::cout << "Введите сторону В: ";
    std::cin >> B;
    std::cout << "Введите градусную меру угла: ";
    std::cin >> angle;
    if ((angle<1 || angle>179) ||  (B<0) || (A<0))
    {
        std::cout << "Такого треугольника не существует";
    } else
    {
        angle = angle * M_PI / 180;
        S = (A*B)/2*sin(angle);
        std::cout << "Площадь треугольника равна: " << S << std::endl;
    }
}