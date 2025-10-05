#include <gtest/gtest.h>
#include "../lib_matrix/matrix.h"

TEST(TestMatrixLib, can_create_matrix) {
    Matrix<float> m;
    EXPECT_EQ(m.get_rows(), 0);
    EXPECT_EQ(m.get_cols(), 0);
}

TEST(TestMatrixLib, can_create_nullsized_matrix) {
    Matrix<float> m(0, 0);
    EXPECT_EQ(m.get_rows(), 0);
    EXPECT_EQ(m.get_cols(), 0);
}

TEST(TestMatrixLib, can_create_sized_matrix) {
    Matrix<float> m(3, 5);
    EXPECT_EQ(m.get_rows(), 3);
    EXPECT_EQ(m.get_cols(), 5);
}

TEST(TestMatrixLib, can_create_vec_matrix) {
    Math_vector<Math_vector<int>> vectors(2);
    int arr1[] = { 1, 2, 3 };
    int arr2[] = { 4,5,6 };
    vectors[0] = Math_vector<int>(arr1, 3);
    vectors[1] = Math_vector<int>(arr2, 3);

    Matrix<int> m(vectors);
    EXPECT_EQ(m.get_rows(), 2);
    EXPECT_EQ(m.get_cols(), 3);
    EXPECT_EQ(m[0][0], 1);
    EXPECT_EQ(m[1][2], 6);
}

TEST(TestMatrixLib, can_copy_matrix) {
    Math_vector<Math_vector<int>> vectors(2);
    int arr1[] = { 1, 2, 3 };
    int arr2[] = { 4,5,6 };
    vectors[0] = Math_vector<int>(arr1, 3);
    vectors[1] = Math_vector<int>(arr2, 3);

    Matrix<int> m(vectors);
    Matrix<int> n(m);
    EXPECT_EQ(n.get_rows(), 2);
    EXPECT_EQ(n.get_cols(), 3);
    EXPECT_EQ(n[0][1], 2);
}

TEST(TestMatrixLib, can_assign_matrix) {
    Matrix<int> m(2, 2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    Matrix<int> n;
    n = m;

    EXPECT_EQ(n.get_rows(), 2);
    EXPECT_EQ(n.get_cols(), 2);
    EXPECT_EQ(n[0][0], 1);
    EXPECT_EQ(n[1][1], 4);
}

TEST(TestMatrixLib, can_self_assign_matrix) {
    Matrix<int> m(2, 2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;
    m = m;

    EXPECT_EQ(m.get_rows(), 2);
    EXPECT_EQ(m.get_cols(), 2);
    EXPECT_EQ(m[0][0], 1);
    EXPECT_EQ(m[1][1], 4);
}

TEST(TestMatrixLib, can_compare_matrix) {
    Matrix<int> m(2, 2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    Matrix<int> n(2, 2);
    n[0][0] = 1; n[0][1] = 2;
    n[1][0] = 3; n[1][1] = 4;

    Matrix<int> k(2, 2);
    k[0][0] = 1; k[0][1] = 2;
    k[1][0] = 3; k[1][1] = 5;

    Matrix<int> l(3, 2);

    EXPECT_TRUE(m == n);
    EXPECT_FALSE(m == k);
    EXPECT_FALSE(m == l);
    EXPECT_TRUE(m != k);
}

TEST(TestMatrixLib, can_add_matrix) {
    Matrix<int> m(2, 2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    Matrix<int> n(2, 2);
    n[0][0] = 5; n[0][1] = 6;
    n[1][0] = 7; n[1][1] = 8;

    Matrix<int> result = m + n;

    EXPECT_EQ(result[0][0], 6);
    EXPECT_EQ(result[0][1], 8);
    EXPECT_EQ(result[1][0], 10);
    EXPECT_EQ(result[1][1], 12);
}

TEST(TestMatrixLib, can_sub_matrix) {
    Matrix<int> m(2, 2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    Matrix<int> n(2, 2);
    n[0][0] = 5; n[0][1] = 6;
    n[1][0] = 7; n[1][1] = 8;

    Matrix<int> result = m - n;

    EXPECT_EQ(result[0][0], -4);
    EXPECT_EQ(result[0][1], -4);
    EXPECT_EQ(result[1][0], -4);
    EXPECT_EQ(result[1][1], -4);
}

TEST(TestMatrixLib, can_mult_val) {
    Matrix<int> m(2, 2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    int n = 5;

    Matrix<int> result = m * n;

    EXPECT_EQ(result[0][0], 5);
    EXPECT_EQ(result[0][1], 10);
    EXPECT_EQ(result[1][0], 15);
    EXPECT_EQ(result[1][1], 20);
}

TEST(TestMatrixLib, can_mult_matrix) {
    Matrix<int> m(2, 3);
    m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
    m[1][0] = 4; m[1][1] = 5; m[1][2] = 6;

    Matrix<int> n(3, 2);
    n[0][0] = 7; n[0][1] = 8;
    n[1][0] = 9; n[1][1] = 10;
    n[2][0] = 11; n[2][1] = 12;

    Matrix<int> result = m * n;

    EXPECT_EQ(result.get_rows(), 2);
    EXPECT_EQ(result.get_cols(), 2);
    EXPECT_EQ(result[0][0], 58);  // 1*7 + 2*9 + 3*11
    EXPECT_EQ(result[0][1], 64);  // 1*8 + 2*10 + 3*12
    EXPECT_EQ(result[1][0], 139); // 4*7 + 5*9 + 6*11
    EXPECT_EQ(result[1][1], 154); // 4*8 + 5*10 + 6*12
}