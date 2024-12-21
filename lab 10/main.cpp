#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

// Функция для проверки, является ли число простым
bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) return false;
    }
    return true;
}

// Функция проверки, начинается ли число с цифры 3
bool startsWithThree(int number) {
    while (number >= 10) {
        number /= 10; // Убираем последнюю цифру
    }
    return number == 3; // Сравниваем первую цифру
}

int main() {
    list<int> sequence; // Односвязный список
    int n;

    // Ввод последовательности натуральных чисел
    cout << "Введите последовательность натуральных чисел (завершите ввод 0):" << endl;
    while (cin >> n && n != 0) {
        if (n > 0) { // Добавляем натуральные числа
            sequence.push_back(n);
        }
    }

    // Проверяем, есть ли числа, начинающиеся с цифры 3
    bool hasThree = false;
    for (int number : sequence) {
        if (startsWithThree(number)) {
            hasThree = true;
            break;
        }
    }

    if (hasThree) {
        // Если числа с первой цифрой 3 есть:
        // Удаляем четные числа, кроме числа 2
        sequence.remove_if([](int num) {
            return (num % 2 == 0 && num != 2);
        });

        // Дублируем простые числа
        for (auto it = sequence.begin(); it != sequence.end(); ++it) {
            if (isPrime(*it)) {
                it = sequence.insert(it, *it); // Дублируем значение
                ++it; // Переходим к следующему элементу
            }
        }
    } else {
        // Если чисел с первой цифрой 3 нет:
        // Сортируем по невозрастанию последней цифры
        sequence.sort([](int a, int b) {
            return (a % 10) > (b % 10); // Сравниваем последние цифры
        });
    }

    // Вывод обработанной последовательности
    cout << "Обработанная последовательность:" << endl;
    for (int number : sequence) {
        cout << number << " ";
    }

    return 0;
}