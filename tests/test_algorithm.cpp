#include <gtest/gtest.h>
#include "../lib_algorithm/algorithm.h"


TEST(TestAlgorithmLib, can_find_local_min3) {
    Matrix<unsigned int> m(3, 3);
    m[0][0] = 80; m[0][1] = 300; m[0][2] = 10;
    m[1][0] = 54; m[1][1] = 77; m[1][2] = 3;
    m[2][0] = 5; m[2][1] = 8; m[2][2] = 6;

    int n = find_local_min(m);

    EXPECT_EQ(n, 3);
}

TEST(TestAlgorithmLib, can_find_local_min2) {
    Matrix<unsigned int> m(2, 2);
    m[0][0] = 80; m[0][1] = 300;
    m[1][0] = 549; m[1][1] = 444;

    int n = find_local_min(m);

    EXPECT_EQ(n, 80);
}