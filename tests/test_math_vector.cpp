#include <gtest/gtest.h>
#include "../lib_math_vector/math_vector.h"

TEST(TestMathVectorLib, can_create_math_vector) {
    Math_vector<float> m();
    ASSERT_NO_THROW(m);
}

TEST(TestMathVectorLib, can_create_sized_math_vector) {
    Math_vector<float> m(5);
    ASSERT_NO_THROW(m);
}

TEST(TestMathVectorLib, add_math_vector) {
    int mass1[5] = {3, 5, 7, 10, 1};
    Math_vector<int> m(mass1, 5);
    int mass2[5] = { 9, 2, 4, 8, 6 };
    Math_vector<int> n(mass2, 5);
    Math_vector<int> result = m + n;
    EXPECT_EQ(result[0], 12);
    EXPECT_EQ(result[1], 7);
    EXPECT_EQ(result[2], 11);
    EXPECT_EQ(result[3], 18);
    EXPECT_EQ(result[4], 7);
}

TEST(TestMathVectorLib, sub_math_vector) {
    int mass1[5] = { 3, 5, 7, 10, 1 };
    Math_vector<int> m(mass1, 5);
    int mass2[5] = { 9, 2, 4, 8, 6 };
    Math_vector<int> n(mass2, 5);
    Math_vector<int> result = m - n;
    EXPECT_EQ(result[0], -6);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 3);
    EXPECT_EQ(result[3], 2);
    EXPECT_EQ(result[4], -5);
}

TEST(TestMathVectorLib, mult_math_vector) {
    int mass1[5] = { 3, 5, 7, 10, 1 };
    Math_vector<int> m(mass1, 5);
    int mass2[5] = { 9, 2, 4, 8, 6 };
    Math_vector<int> n(mass2, 5);
    int result = m * n;
    EXPECT_EQ(result, 151);
}

TEST(TestMathVectorLib, mult_val) {
    int mass1[5] = { 3, 5, 7, 10, 1 };
    Math_vector<int> m(mass1, 5);
    int n = -7;
    Math_vector<int> result = m * n;
    EXPECT_EQ(result[0], -21);
    EXPECT_EQ(result[1], -35);
    EXPECT_EQ(result[2], -49);
    EXPECT_EQ(result[3], -70);
    EXPECT_EQ(result[4], -7);
}

