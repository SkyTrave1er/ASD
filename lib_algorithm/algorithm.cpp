#include "../lib_algorithm/algorithm.h"



int find_local_min(const Matrix<unsigned int>& matr) {
    int n = matr.get_rows();

    int i = rand() % n;
    int j = rand() % n;

    while (1) {
        unsigned int current = matr[i][j];
        bool is_min = true;

        if (j > 0 && matr[i][j - 1] < current) {
            j = j - 1;
            is_min = false;
            continue;
        }

        if (j < n - 1 && matr[i][j + 1] < current) {
            j = j + 1;
            is_min = false;
            continue;
        }

        if (i > 0 && matr[i - 1][j] < current) {
            i = i - 1;
            is_min = false;
            continue;
        }

        if (i < n - 1 && matr[i + 1][j] < current) {
            i = i + 1;
            is_min = false;
            continue;
        }

        if (is_min) {
            return matr[i][j];
        }
    }
}