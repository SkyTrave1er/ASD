#include "../lib_algorithm/algorithm.h"

int find_local_min(const Matrix<unsigned int>& matr) {
    int min = 100000000;
    for (int i = 0; i < matr.get_rows(); i++) {
        for (int j = 0; j < matr.get_cols(); j++) {
            if ((i == 0) && (j == 0) && 
                (matr[i][j] < matr[i][j + 1] || matr[i][j] < matr[i + 1][j]
                || matr[i][j] < matr[i + 1][j + 1])) {
                if (min > matr[i][j]) {
                    min = matr[i][j];
                }
            }
            
            if ((i == 0) && (j != 0) && (j != matr.get_cols() - 1) &&
                (matr[i][j] < matr[i][j + 1] || matr[i][j] < matr[i + 1][j]
                || matr[i][j] < matr[i][j - 1])) {
                if (min > matr[i][j]) {
                    min = matr[i][j];
                }
            }

            if ((i == 0) && (j == matr.get_cols() - 1) &&
                (matr[i][j] < matr[i + 1][j]
                || matr[i][j] < matr[i][j - 1])) {
                if (min > matr[i][j]) {
                    min = matr[i][j];
                }
            }

            if ((i != 0) && (i != matr.get_rows() - 1) && (j == 0) &&
                (matr[i][j] < matr[i + 1][j]
                || matr[i][j] < matr[i][j + 1] || matr[i][j] < matr[i - 1][j])) {
                if (min > matr[i][j]) {
                    min = matr[i][j];
                }
            }

            if ((i == matr.get_rows() - 1) && (j == 0) &&
                (matr[i][j] < matr[i][j + 1] || matr[i][j] < matr[i - 1][j])) {
                if (min > matr[i][j]) {
                    min = matr[i][j];
                }
            }

            if ((i == matr.get_rows() - 1) && (j != 0) && (j != matr.get_cols() - 1) &&
                (matr[i][j] < matr[i][j + 1] || matr[i][j] < matr[i - 1][j]
                || matr[i][j] < matr[i][j - 1])) {
                if (min > matr[i][j]) {
                    min = matr[i][j];
                }
            }

            if ((i == matr.get_rows() - 1) && (j == matr.get_cols() - 1) &&
                (matr[i][j] < matr[i - 1][j] || matr[i][j] < matr[i][j - 1])) {
                if (min > matr[i][j]) {
                    min = matr[i][j];
                }
            }

            if ((i != 0) && (i != matr.get_rows() - 1) && (j == matr.get_cols() - 1) &&
                (matr[i][j] < matr[i - 1][j] || matr[i][j] < matr[i + 1][j] || matr[i][j] < matr[i][j - 1])) {
                if (min > matr[i][j]) {
                    min = matr[i][j];
                }
            }

            if ((i != 0) && (i != matr.get_rows() - 1) && (j != 0) && (j != matr.get_cols() - 1) &&
                (matr[i][j] < matr[i - 1][j] || matr[i][j] < matr[i + 1][j]
                || matr[i][j] < matr[i][j - 1] || matr[i][j] < matr[i][j + 1])) {
                if (min > matr[i][j]) {
                    min = matr[i][j];
                }
            }
        }
    }
    return min;
}