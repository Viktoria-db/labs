#include <iostream>

int main() {
    int n=0;
    std::cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    int product = 1;
    int max_number = 0;
    int max_index = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] % 10 == 2) {
            product *= A[i];

            if (A[i] > max_number) {
                max_number = A[i];
                max_index = i;
            }
        }
    }

    std::cout << "Произведение чисел, оканчивающихся на 2: " << product << std::endl;
    std::cout << "Максимальное число, оканчивающееся на 2: " << max_number << std::endl;
    std::cout << "Номер максимального числа: " << max_index+1  << std::endl;

    int N, digit, max_count = 0, current_count;
    char most_frequent_digit;

    std::cout << "Введите натуральное число N (N < 10^9): ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "Введено некорректное число." << std::endl;
        return 1;
    }

    int digit_counts[10] = {0};


    while (N > 0) {
        digit = N % 10;
        digit_counts[digit]++;
        N /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (digit_counts[i] > max_count) {
            max_count = digit_counts[i];
            most_frequent_digit = i + '0';
        }
    }

    std::cout << "Наиболее часто встречающаяся цифра: " << most_frequent_digit << std::endl;

}