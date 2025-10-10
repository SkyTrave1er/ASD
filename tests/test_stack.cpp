#include <gtest/gtest.h>
#include "../lib_stack/stack.h"

TEST(TestStackLib, can_create_stack) {
    Stack<int> s(10);
    EXPECT_EQ(s.get_top(), -1);
    EXPECT_EQ(s.get_size(), 10);
}

TEST(TestStackLib, can_copy_stack) {
    Stack<int> s1(4);
    s1.push(5);
    s1.push(8);

    Stack<int> s2(s1);

    EXPECT_EQ(s2.get_top(), 1);
    EXPECT_EQ(s2.top(), 8);
    EXPECT_EQ(s2.get_size(), 4);
}

TEST(TestStackLib, can_push_stack) {
    Stack<int> s(4);
    s.push(5);
    s.push(8);

    EXPECT_EQ(s.get_top(), 1);
    EXPECT_EQ(s.top(), 8);
    EXPECT_EQ(s.get_size(), 4);
}

TEST(TestStackLib, throw_when_push_stack) {
    Stack<int> s(4);
    s.push(5);
    s.push(8);
    s.push(90);
    s.push(14);

    EXPECT_ANY_THROW(s.push(1));
}

TEST(TestStackLib, can_pop_stack) {
    Stack<int> s(4);
    s.push(5);
    s.push(8);
    s.push(7);

    s.pop();
    s.pop();

    EXPECT_EQ(s.get_top(), 0);
    EXPECT_EQ(s.top(), 5);
    EXPECT_EQ(s.get_size(), 4);
}

TEST(TestStackLib, throw_when_pop_stack) {
    Stack<int> s(4);
    s.push(5);
    s.push(8);
    s.pop();
    s.pop();

    EXPECT_ANY_THROW(s.pop());
}

TEST(TestStackLib, can_top_stack) {
    Stack<int> s(4);
    s.push(5);
    s.push(8);
    s.pop();
    s.push(7);
    s.pop();

    EXPECT_EQ(s.get_top(), 0);
    EXPECT_EQ(s.top(), 5);
    EXPECT_EQ(s.get_size(), 4);
}

TEST(TestStackLib, throw_when_top_stack) {
    Stack<int> s(4);
    s.push(5);
    s.push(8);
    s.pop();
    s.pop();

    EXPECT_ANY_THROW(s.top());
}

TEST(TestStackLib, empty_stack) {
    Stack<int> s(4);
    s.push(5);
    s.push(8);
    s.pop();
    s.pop();

    EXPECT_EQ(s.is_empty(), 1);
}

TEST(TestStackLib, throw_when_empty_stack) {
    Stack<int> s(4);
    s.push(5);
    s.push(8);
    s.pop();

    EXPECT_EQ(s.is_empty(), 0);
}

TEST(TestStackLib, full_stack) {
    Stack<int> s(4);
    s.push(5);
    s.push(8);
    s.push(22);
    s.push(99);

    EXPECT_EQ(s.is_full(), 1);
}

TEST(TestStackLib, throw_when_full_stack) {
    Stack<int> s(4);
    s.push(5);
    s.push(8);

    EXPECT_EQ(s.is_full(), 0);
}

TEST(TestStackLib, can_clear_stack) {
    Stack<int> s(4);
    s.push(5);
    s.push(8);
    s.clear();

    EXPECT_EQ(s.get_top(), -1);
}
