#include <gtest/gtest.h>
#include "../lib_list/list.h"

TEST(TestListLib, can_create_list) {
    List<int> l;

    ASSERT_NO_THROW(l);
    EXPECT_EQ(l.head(), nullptr);
    EXPECT_EQ(l.tail(), nullptr);
    EXPECT_EQ(l.get_count(), 0);
}

TEST(TestListLib, can_copy_list) {
    List<int> l1;
    l1.push_back(5);
    l1.push_back(8);

    List<int> l2(l1);

    EXPECT_EQ(l2.get_count(), 2);
    EXPECT_EQ(l2.tail()->_value, 8);
    EXPECT_EQ(l2.head()->_value, 5);
}

TEST(TestListLib, can_push_list) {
    List<int> l;
    l.push_back(5);
    l.push_front(8);
    l.push_front(1);
    l.push_back(4);

    EXPECT_EQ(l.head()->_value, 1);
    EXPECT_EQ(l.tail()->_value, 4);
    EXPECT_EQ(l.get_count(), 4);
}

TEST(TestListLib, can_pop_list) {
    List<int> l;
    l.push_back(5);
    l.push_back(8);
    l.push_back(7);

    l.pop_front();
    l.pop_back();

    EXPECT_EQ(l.tail()->_value, 8);
    EXPECT_EQ(l.head()->_value, 8);
    EXPECT_EQ(l.get_count(), 1);
}

TEST(TestListLib, throw_when_pop_list) {
    List<int> l;

    EXPECT_ANY_THROW(l.pop_front());
    EXPECT_ANY_THROW(l.pop_back());
}

TEST(TestListLib, can_head_list) {
    List<int> l;
    l.push_front(5);
    l.push_back(8);
    l.pop_back();
    l.push_front(7);
    l.pop_front();

    EXPECT_EQ(l.head()->_value, 5);
}

TEST(TestListLib, can_tail_list) {
    List<int> q;
    q.push_back(5);
    q.push_front(8);
    q.pop_back();
    q.push_back(7);
    q.pop_front();

    EXPECT_EQ(q.tail()->_value, 7);
}

TEST(TestListLib, empty_list) {
    List<int> l;
    l.push_back(5);
    l.push_back(8);
    l.pop_front();
    l.pop_front();

    EXPECT_EQ(l.is_empty(), 1);
    EXPECT_EQ(l.head(), nullptr);
    EXPECT_EQ(l.tail(), nullptr);
}

TEST(TestListLib, throw_when_empty_list) {
    List<int> l;
    l.push_back(5);
    l.push_back(8);
    l.pop_back();

    EXPECT_EQ(l.is_empty(), 0);
}

TEST(TestListLib, can_insert_list) {
    List<int> l;
    l.push_back(5);
    l.push_front(8);
    l.push_front(1);  //  198534
    l.push_back(4);

    l.insert(l.head()->_next->_next, 3);
    l.insert(1, 9);

    EXPECT_EQ(l.head()->_next->_value, 9);
    EXPECT_EQ(l.head()->_next->_next->_next->_next->_value, 3);
    EXPECT_EQ(l.get_count(), 6);
}

TEST(TestListLib, throw_when_insert_list) {
    List<int> l;

    EXPECT_ANY_THROW(l.insert(l.head(), 7));
    EXPECT_ANY_THROW(l.insert(l.tail(), 2));
    EXPECT_ANY_THROW(l.insert(6, 6));
}

TEST(TestListLib, can_erase_list) {
    List<int> l;
    l.push_back(5);
    l.push_back(8);
    l.push_back(1);
    l.push_back(7);

    l.erase(l.head()->_next);
    l.erase(1);

    EXPECT_EQ(l.tail()->_value, 7);
    EXPECT_EQ(l.head()->_value, 5);
    EXPECT_EQ(l.get_count(), 2);
}

TEST(TestListLib, throw_when_erase_list) {
    List<int> l;

    EXPECT_ANY_THROW(l.erase(l.head()));
    EXPECT_ANY_THROW(l.erase(5));
}