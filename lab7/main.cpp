#include "test.h"

int main() {
    int n;
    std::cout << "Введите размер матрицы (n<=100): ";
    std::cin >> n;



    int A[100][100];
    zal::read_matrix(A, n);

    int max_element, min_element;
    //zal::find_max_min(A, n, max_element, min_element);

    if (max_element + min_element == 0) {
       // zal::sort_rows(A, n);
        //zal::print_matrix(A, n);
    } else {
        std::cout << "Сумма наибольшего и наименьшего элементов не равна нулю." << std::endl;
    }

    return 0;
}