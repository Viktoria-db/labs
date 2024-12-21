// Функция чтения матрицы
#include "functions.hpp"

namespace zal // upa
{
    void read_matrix(int A[][100], int n) {
        std::cout << "Введите элементы матрицы:" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> A[i][j];
            }
        }
    }

// Функция нахождения наибольшего и наименьшего элемента матрицы
    void find_max_min(int A[][100], int n, int &max_element, int &min_element) {
        max_element = A[0][0];
        min_element = A[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] > max_element) {
                    max_element = A[i][j];
                }
                if (A[i][j] < min_element) {
                    min_element = A[i][j];
                }
            }
        }
    }

// Функция проверки наличия цифры 8 в строке
    bool has_digit_8(int row[], int n) {
        for (int j = 0; j < n; j++) {
            if (abs(row[j]) % 10 == 8) {
                return true;
            }
        }
        return false;
    }


// Функция сортировки строк матрицы
    void sort_rows(int A[][100], int n) {
        for (int i = 0; i < n; i++) {
            if (has_digit_8(A[i], n)) {
                std::sort(A[i], A[i] + n);
            }
        }
    }

// Функция записи матрицы
    void print_matrix(int A[][100], int n) {
        std::cout << "Измененная матрица:" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << A[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}