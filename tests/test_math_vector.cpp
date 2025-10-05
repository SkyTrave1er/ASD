#include <gtest/gtest.h>
#include "../lib_math_vector/math_vector.h"

TEST(TestMathVectorLib, can_create_math_vector) {
    Math_vector<float> m;
    EXPECT_EQ(m.size(), 0);
}

TEST(TestMathVectorLib, can_create_nullsized_math_vector) {
    Math_vector<float> m(0);
    EXPECT_EQ(m.size(), 0);
}

TEST(TestMathVectorLib, can_create_sized_math_vector) {
    Math_vector<float> m(5);
    EXPECT_EQ(m.size(), 5);
}

TEST(TestMathVectorLib, can_create_arr_math_vector) {
    int arr[] = { 1, 2, 3 };
    Math_vector<int> m(arr, 3);
    EXPECT_EQ(m.size(), 3);
    EXPECT_EQ(m[0], 1);
    EXPECT_EQ(m[1], 2);
    EXPECT_EQ(m[2], 3);
}

TEST(TestMathVectorLib, can_copy_math_vector) {
    int arr[] = { 1, 2, 3 };
    Math_vector<int> m(arr, 3);
    Math_vector<int> n(m);
    EXPECT_EQ(n.size(), 3);
    EXPECT_EQ(n[0], 1);
    EXPECT_EQ(n[1], 2);
    EXPECT_EQ(n[2], 3);
}

TEST(TestMathVectorLib, can_assign_math_vector) {
    Math_vector<int> m(3);
    m[0] = 1;
    m[1] = 2;
    m[2] = 3;

    Math_vector<int> n;
    n = m;
    EXPECT_EQ(n.size(), 3);
    EXPECT_EQ(n[0], 1);
    EXPECT_EQ(n[1], 2);
    EXPECT_EQ(n[2], 3);
}

TEST(TestMathVectorLib, can_self_assign_math_vector) {
    Math_vector<int> m(3);
    m[0] = 1;
    m[1] = 2;
    m[2] = 3;

    m = m;
    EXPECT_EQ(m.size(), 3);
    EXPECT_EQ(m[0], 1);
    EXPECT_EQ(m[1], 2);
    EXPECT_EQ(m[2], 3);
}

TEST(TestMathVectorLib, can_compare_math_vector) {
    Math_vector<int> m(2);
    m[0] = 1;
    m[1] = 2;

    Math_vector<int> n(2);
    n[0] = 1;
    n[1] = 2;

    Math_vector<int> k(2);
    k[0] = 1;
    k[1] = 3;

    Math_vector<int> l(3);

    EXPECT_TRUE(m == n);
    EXPECT_FALSE(m == k);
    EXPECT_FALSE(m == l);
    EXPECT_TRUE(m != k);
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

TEST(TestMathVectorLib, throw_when_add_math_vector) {
    int mass1[5] = { 3, 5, 7, 10, 1 };
    Math_vector<int> m(mass1, 5);
    int mass2[6] = { 9, 2, 4, 8, 6, 14 };
    Math_vector<int> n(mass2, 6);
    EXPECT_THROW(Math_vector<int> result = m + n, std::invalid_argument);
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

TEST(TestMathVectorLib, throw_when_sub_math_vector) {
    int mass1[5] = { 3, 5, 7, 10, 1 };
    Math_vector<int> m(mass1, 5);
    int mass2[6] = { 9, 2, 4, 8, 6, 14 };
    Math_vector<int> n(mass2, 6);
    EXPECT_THROW(Math_vector<int> result = m - n, std::invalid_argument);
}

TEST(TestMathVectorLib, mult_math_vector) {
    int mass1[5] = { 3, 5, 7, 10, 1 };
    Math_vector<int> m(mass1, 5);
    int mass2[5] = { 9, 2, 4, 8, 6 };
    Math_vector<int> n(mass2, 5);
    int result = m * n;
    EXPECT_EQ(result, 151);
}

TEST(TestMathVectorLib, throw_when_mult_math_vector) {
    int mass1[5] = { 3, 5, 7, 10, 1 };
    Math_vector<int> m(mass1, 5);
    int mass2[6] = { 9, 2, 4, 8, 6, 14 };
    Math_vector<int> n(mass2, 6);
    EXPECT_THROW(Math_vector<int> result = m * n, std::invalid_argument);
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

TEST(TestMathVectorLib, multeq_val) {
    int mass1[5] = { 3, 5, 7, 10, 1 };
    Math_vector<int> m(mass1, 5);
    int n = -7;
    m *= n;
    EXPECT_EQ(m[0], -21);
    EXPECT_EQ(m[1], -35);
    EXPECT_EQ(m[2], -49);
    EXPECT_EQ(m[3], -70);
    EXPECT_EQ(m[4], -7);
}

TEST(TestMathVectorLib, addeq_vec) {
    int mass1[5] = { 3, 5, 7, 10, 1 };
    Math_vector<int> m(mass1, 5);
    int mass2[5] = { 9, 2, 4, 8, 6 };
    Math_vector<int> n(mass2, 5);
    m += n;
    EXPECT_EQ(m[0], 12);
    EXPECT_EQ(m[1], 7);
    EXPECT_EQ(m[2], 11);
    EXPECT_EQ(m[3], 18);
    EXPECT_EQ(m[4], 7);
}

TEST(TestMathVectorLib, subeq_vec) {
    int mass1[5] = { 3, 5, 7, 10, 1 };
    Math_vector<int> m(mass1, 5);
    int mass2[5] = { 9, 2, 4, 8, 6 };
    Math_vector<int> n(mass2, 5);
    m -= n;
    EXPECT_EQ(m[0], -6);
    EXPECT_EQ(m[1], 3);
    EXPECT_EQ(m[2], 3);
    EXPECT_EQ(m[3], 2);
    EXPECT_EQ(m[4], -5);
}


