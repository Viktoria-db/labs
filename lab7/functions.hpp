#pragma once
#include <iostream>
#include <algorithm>

namespace zal // upa
{
    void read_matrix(int A[][100], int n);
    void find_max_min(int A[][100], int n, int& max_element, int& min_element);
    bool has_digit_8(int row[], int n);
    void sort_rows(int A[][100], int n);
    void print_matrix(int A[][100], int n);
}

