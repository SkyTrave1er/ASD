#include <gtest/gtest.h>
#include "../lib_algorithm/algorithm.h"
#include <time.h>
#include <cstdlib>



TEST(TestAlgorithmLib, can_find_different_local_min) {
    srand(time(0));
    Matrix<unsigned int> m(3, 3);
    m[0][0] = 80; m[0][1] = 300; m[0][2] = 10;
    m[1][0] = 54; m[1][1] = 77; m[1][2] = 3;
    m[2][0] = 5; m[2][1] = 8; m[2][2] = 6;

    int n = find_local_min(m);

    EXPECT_TRUE(n == 3 || n == 5);
}

TEST(TestAlgorithmLib, can_find_center_local_min) {
    srand(time(0));
    Matrix<unsigned int> m(3, 3);
    m[0][0] = 10; m[0][1] = 11; m[0][2] = 9;
    m[1][0] = 4; m[1][1] = 1; m[1][2] = 8;
    m[2][0] = 5; m[2][1] = 6; m[2][2] = 7;

    int n = find_local_min(m);

    EXPECT_EQ(n, 1);
}

TEST(TestAlgorithmLib, can_find_corner_local_min) {
    srand(time(0));
    Matrix<unsigned int> m(3, 3);
    m[0][0] = 7; m[0][1] = 8; m[0][2] = 1;
    m[1][0] = 6; m[1][1] = 9; m[1][2] = 2;
    m[2][0] = 5; m[2][1] = 4; m[2][2] = 3;

    int n = find_local_min(m);

    EXPECT_EQ(n, 1);
}

TEST(TestAlgorithmLib, can_find_local_min_44) {
    srand(time(0));
    Matrix<unsigned int> m(3, 3);
    m[0][0] = 7; m[0][1] = 8; m[0][2] = 14; m[0][3] = 11;
    m[1][0] = 6; m[1][1] = 0; m[1][2] = 2; m[1][3] = 13;
    m[2][0] = 9; m[2][1] = 4; m[2][2] = 1; m[2][3] = 10;
    m[3][0] = 5; m[3][1] = 6; m[3][2] = 3; m[3][3] = 12;

    int n = find_local_min(m);

    EXPECT_TRUE(n == 0 || n == 1 || n == 5 || n == 11);
}

TEST(TestAlgorithmLib, can_check_brackets_v1) {
    std::string s = "()()";
    bool b = check_breckets(s);
    EXPECT_TRUE(b);
}

TEST(TestAlgorithmLib, can_check_brackets_v2) {
    std::string s = "[(()())({})]";
    bool b = check_breckets(s);
    EXPECT_TRUE(b);
}

TEST(TestAlgorithmLib, can_check_brackets_v3) {
    std::string s = "[(){[()()]({()})}]";
    bool b = check_breckets(s);
    EXPECT_TRUE(b);
}

TEST(TestAlgorithmLib, can_check_brackets_v4) {
    std::string s = "(a+b)*(c-d)";
    bool b = check_breckets(s);
    EXPECT_TRUE(b);
}

TEST(TestAlgorithmLib, throw_check_brackets_v1) {
    std::string s = "{()()";
    bool b = check_breckets(s);
    EXPECT_FALSE(b);
}

TEST(TestAlgorithmLib, throw_check_brackets_v2) {
    std::string s = "()){()}";
    bool b = check_breckets(s);
    EXPECT_FALSE(b);
}

//TEST(TestAlgorithmLib, throw_check_brackets_v3) {
//    std::string s = "((()()(()))";
//    bool b = check_breckets(s);
//    EXPECT_FALSE(b);
//}

//TEST(TestAlgorithmLib, throw_check_brackets_v4) {
//    std::string s = "]})";
//    bool b = check_breckets(s);
//    EXPECT_FALSE(b);
//}
//
//TEST(TestAlgorithmLib, throw_check_brackets_v5) {
//    std::string s = "[{(";
//    bool b = check_breckets(s);
//    EXPECT_FALSE(b);
//}

TEST(TestAlgorithmLib, throw_check_brackets_v6) {
    std::string s = "{(})";
    bool b = check_breckets(s);
    EXPECT_FALSE(b);
}

TEST(TestAlgorithmLib, throw_check_brackets_v7) {
    std::string s = "[(]{)}";
    bool b = check_breckets(s);
    EXPECT_FALSE(b);
}