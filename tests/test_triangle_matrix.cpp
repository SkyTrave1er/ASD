#include <gtest/gtest.h>
#include "../lib_triangle_matrix/triangle_matrix.h"

TEST(TestTriangleMatrixLib, can_create_tr_matrix) {
    Triangle_matrix<float> m;
    EXPECT_EQ(m.get_n(), 0);
}

TEST(TestTriangleMatrixLib, can_create_sized_tr_matrix) {
    Triangle_matrix<float> m(3);
    EXPECT_EQ(m.get_n(), 3);
    EXPECT_EQ(m[0].get_start_index(), 0);
    EXPECT_EQ(m[1].get_start_index(), 1);
    EXPECT_EQ(m[2].get_start_index(), 2);
}

TEST(TestTriangleMatrixLib, can_create_data_tr_matrix) {
    Triangle_matrix<float> m(3);
    m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
                 m[1][1] = 4; m[1][2] = 5;
                              m[2][2] = 6;
    EXPECT_EQ(m.get_n(), 3);
    EXPECT_EQ(m[0][0], 1);
    EXPECT_EQ(m[0][1], 2);
    EXPECT_EQ(m[0][2], 3);
    EXPECT_EQ(m[1][1], 4);
    EXPECT_EQ(m[1][2], 5);
    EXPECT_EQ(m[2][2], 6);
}

TEST(TestTriangleMatrixLib, can_copy_tr_matrix) {
    Triangle_matrix<float> m(3);
    m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
    m[1][1] = 4; m[1][2] = 5;
    m[2][2] = 6;

    Triangle_matrix<float> n(m);
    EXPECT_EQ(n.get_n(), 3);
    EXPECT_EQ(n[0][0], 1);
    EXPECT_EQ(n[0][1], 2);
    EXPECT_EQ(n[0][2], 3);
    EXPECT_EQ(n[1][1], 4);
    EXPECT_EQ(n[1][2], 5);
    EXPECT_EQ(n[2][2], 6);
}

TEST(TestTriangleMatrixLib, can_assign_tr_matrix) {
    Triangle_matrix<float> m(3);
    m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
    m[1][1] = 4; m[1][2] = 5;
    m[2][2] = 6;

    Triangle_matrix<float> n;
    n = m;

    EXPECT_EQ(n.get_n(), 3);
    EXPECT_EQ(n[0][0], 1);
    EXPECT_EQ(n[0][1], 2);
    EXPECT_EQ(n[0][2], 3);
    EXPECT_EQ(n[1][1], 4);
    EXPECT_EQ(n[1][2], 5);
    EXPECT_EQ(n[2][2], 6);
}

TEST(TestTriangleMatrixLib, can_mult_val) {
    Triangle_matrix<int> m(3);
    m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
    m[1][1] = 4; m[1][2] = 5;
    m[2][2] = 6;

    int n = 5;
    Triangle_matrix<int> result;
    result = m * n;
    EXPECT_EQ(result.get_n(), 3);
    EXPECT_EQ(result[0][0], 5);
    EXPECT_EQ(result[0][1], 10);
    EXPECT_EQ(result[0][2], 15);
    EXPECT_EQ(result[1][1], 20);
    EXPECT_EQ(result[1][2], 25);
    EXPECT_EQ(result[2][2], 30);
}

TEST(TestTriangleMatrixLib, can_add_tr_matrix) {
    Triangle_matrix<int> m(3);
    m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
    m[1][1] = 4; m[1][2] = 5;
    m[2][2] = 6;

    Triangle_matrix<int> n(3);
    n[0][0] = 6; n[0][1] = 5; n[0][2] = 4;
    n[1][1] = 3; n[1][2] = 2;
    n[2][2] = 1;

    Triangle_matrix<int> result;
    result = m + n;
    EXPECT_EQ(result.get_n(), 3);
    EXPECT_EQ(result[0][0], 7);
    EXPECT_EQ(result[0][1], 7);
    EXPECT_EQ(result[0][2], 7);
    EXPECT_EQ(result[1][1], 7);
    EXPECT_EQ(result[1][2], 7);
    EXPECT_EQ(result[2][2], 7);
}

TEST(TestTriangleMatrixLib, can_sub_tr_matrix) {
    Triangle_matrix<int> m(3);
    m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
    m[1][1] = 4; m[1][2] = 5;
    m[2][2] = 6;

    Triangle_matrix<int> n(3);
    n[0][0] = 6; n[0][1] = 5; n[0][2] = 4;
    n[1][1] = 3; n[1][2] = 2;
    n[2][2] = 1;

    Triangle_matrix<int> result;
    result = m - n;
    EXPECT_EQ(result.get_n(), 3);
    EXPECT_EQ(result[0][0], -5);
    EXPECT_EQ(result[0][1], -3);
    EXPECT_EQ(result[0][2], -1);
    EXPECT_EQ(result[1][1], 1);
    EXPECT_EQ(result[1][2], 3);
    EXPECT_EQ(result[2][2], 5);
}

TEST(TestTriangleMatrixLib, can_mult_tr_matrix) {
    Triangle_matrix<int> m(3);
    m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
    m[1][1] = 4; m[1][2] = 5;
    m[2][2] = 6;

    Triangle_matrix<int> n(3);
    n[0][0] = 6; n[0][1] = 5; n[0][2] = 4;
    n[1][1] = 3; n[1][2] = 2;
    n[2][2] = 1;

    Triangle_matrix<int> result;
    result = m * n;
    EXPECT_EQ(result.get_n(), 3);
    EXPECT_EQ(result[0][0], 6);
    EXPECT_EQ(result[0][1], 11);
    EXPECT_EQ(result[0][2], 11);
    EXPECT_EQ(result[1][1], 12);
    EXPECT_EQ(result[1][2], 13);
    EXPECT_EQ(result[2][2], 6);
}
