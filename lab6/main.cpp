#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int productOfDigits(int n) {
    if (n == 0) return 0;
    int product = 1;
    while (n > 0) {
        product *= (n % 10);
        n /= 10;
    }
    return product;
}

int firstDigit(int n) {
    if (n == 0) return 0;
    while (n >= 10) {
        n /= 10;
    }
    return n;
}


int main() {
    int n;

    std::cout << "Задача 1:" << std::endl;
    std::cout << "Введите количество чисел: ";
    std::cin >> n;
    std::vector<int> arr1;
    arr1.reserve(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr1[i];
    }

    bool hasPrime = false;
    for (int num : arr1) {
        if (isPrime(num)) {
            hasPrime = true;
            break;
        }
    }
    if (hasPrime) {
        std::sort(arr1.begin(), arr1.end());
    }
    for (int num : arr1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    std::cout << "Задача 2" << std::endl;
    std::cout << "Введите количество чисел: ";
    std::cin >> n;
    std::vector<int> arr2(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr2[i];
    }
    std::sort(arr2.begin(), arr2.end(), [](int a, int b) {
        int prod_a = productOfDigits(a);
        int prod_b = productOfDigits(b);
        if (prod_a != prod_b) return prod_a < prod_b;
        int first_a = firstDigit(a);
        int first_b = firstDigit(b);
        if (first_a != first_b) return first_a < first_b;
        return a < b;
    });
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    std::cout << "Задача 3:" << std::endl;
    int rows = 0;
    int cols = 0;
    std::cout << "Введите количество строк и столбцов матрицы: ";
    std::cin >> rows >> cols;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int minEvenCount = rows + 1;
    int minEvenRow = -1;
    for (int i = 0; i < rows; ++i) {
        int evenCount = 0;
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] % 2 == 0) evenCount++;
        }
        if (evenCount < minEvenCount) {
            minEvenCount = evenCount;
            minEvenRow = i;
        }
    }

    for (int j = 0; j < cols; ++j) {
        matrix[minEvenRow][j] = matrix[minEvenRow][j] * matrix[minEvenRow][j];
    }
    std::cout << "Матрица после замены:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    std::cout << "Задача 4:" << std::endl;
    std::cout << "Введите количество чисел: ";
    std::cin >> n;
    std::vector<int> arr4;
    arr4.reserve(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr4[i];
    }

    std::vector<int> unique_elements;
    for (int x : arr4) {
        bool found = false;
        for (int y : unique_elements) {
            if (x == y) {
                found = true;
                break;
            }
        }
        if (!found) unique_elements.push_back(x);
    }

    std::cout << "Последовательность с удаленными и продублированными элементами: ";
    for (int x : unique_elements) std::cout << x << " ";
    std::cout << std::endl;


    std::cout << "Задача 5:" << std::endl;
    std::cout << "Введите количество чисел: ";
    std::cin >> n;
    std::vector<int> arr5;
    arr5.reserve(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr5[i];
    }

    std::vector<int> result5;
    for (int num : arr5) {
        if (productOfDigits(num) != 180) {
            result5.push_back(num);
            std::string s = std::to_string(num);
            if (s.length() > 1 && s.back() == '1' && s[0] == '1') result5.push_back(num);
        }
    }
    std::cout << "Последовательность после удаления и дублирования: ";
    for (int num : result5) std::cout << num << " ";
    std::cout << std::endl;


    return 0;
}