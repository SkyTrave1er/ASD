#include <gtest/gtest.h>
#include "../lib_dl_list/dl_list.h"

TEST(TestDl_listLib, can_create_Dl_list) {
    Dl_list<int> l;

    ASSERT_NO_THROW(l);
    EXPECT_EQ(l.head(), nullptr);
    EXPECT_EQ(l.tail(), nullptr);
    EXPECT_EQ(l.get_count(), 0);
}

TEST(TestDl_listLib, can_copy_Dl_list) {
    Dl_list<int> l1;
    l1.push_back(5);
    l1.push_back(8);

    Dl_list<int> l2(l1);

    EXPECT_EQ(l2.get_count(), 2);
    EXPECT_EQ(l2.tail()->_value, 8);
    EXPECT_EQ(l2.head()->_value, 5);
}

TEST(TestDl_listLib, can_push_Dl_list) {
    Dl_list<int> l;
    l.push_back(5);
    l.push_front(8);
    l.push_front(1);
    l.push_back(4);

    EXPECT_EQ(l.head()->_value, 1);
    EXPECT_EQ(l.tail()->_value, 4);
    EXPECT_EQ(l.get_count(), 4);
}

TEST(TestDl_listLib, can_pop_Dl_list) {
    Dl_list<int> l;
    l.push_back(5);
    l.push_back(8);
    l.push_back(7);

    l.pop_front();
    l.pop_back();

    EXPECT_EQ(l.tail()->_value, 8);
    EXPECT_EQ(l.head()->_value, 8);
    EXPECT_EQ(l.get_count(), 1);
}

TEST(TestDl_listLib, throw_when_pop_Dl_list) {
    Dl_list<int> l;

    EXPECT_ANY_THROW(l.pop_front());
    EXPECT_ANY_THROW(l.pop_back());
}

TEST(TestDl_listLib, can_head_Dl_list) {
    Dl_list<int> l;
    l.push_front(5);
    l.push_back(8);
    l.pop_back();
    l.push_front(7);
    l.pop_front();

    EXPECT_EQ(l.head()->_value, 5);
}

TEST(TestDl_listLib, can_tail_Dl_list) {
    Dl_list<int> q;
    q.push_back(5);
    q.push_front(8);
    q.pop_back();
    q.push_back(7);
    q.pop_front();

    EXPECT_EQ(q.tail()->_value, 7);
}

TEST(TestDl_listLib, empty_Dl_list) {
    Dl_list<int> l;
    l.push_back(5);
    l.push_back(8);
    l.pop_front();
    l.pop_front();

    EXPECT_EQ(l.is_empty(), 1);
    EXPECT_EQ(l.head(), nullptr);
    EXPECT_EQ(l.tail(), nullptr);
}

TEST(TestDl_listLib, throw_when_empty_Dl_list) {
    Dl_list<int> l;
    l.push_back(5);
    l.push_back(8);
    l.pop_back();

    EXPECT_EQ(l.is_empty(), 0);
}

TEST(TestDl_listLib, can_insert_Dl_list) {
    Dl_list<int> l;
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

TEST(TestDl_listLib, throw_when_insert_Dl_list) {
    Dl_list<int> l;

    EXPECT_ANY_THROW(l.insert(l.head(), 7));
    EXPECT_ANY_THROW(l.insert(l.tail(), 2));
    EXPECT_ANY_THROW(l.insert(6, 6));
}

TEST(TestDl_listLib, can_erase_Dl_list) {
    Dl_list<int> l;
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

TEST(TestDl_listLib, throw_when_erase_Dl_list) {
    Dl_list<int> l;

    EXPECT_ANY_THROW(l.erase(l.head()));
    EXPECT_ANY_THROW(l.erase(5));
}

TEST(TestDl_listLib, can_read_iterator_Dl_list) {
    Dl_list<int> l;

    for (int i = 0; i < 3; i++) {
        l.push_back(i + 1);
    }
    auto it = l.begin();
    EXPECT_EQ(*it, 1);

    it++;
    EXPECT_EQ(*it, 2);

    it++;
    EXPECT_EQ(*it, 3);
}

TEST(TestDl_listLib, can_write_iterator_Dl_list) {
    Dl_list<int> l;

    for (int i = 0; i < 3; i++) {
        l.push_back((i + 1) * 10);
    }

    auto it = l.begin();
    *it = 100;
    EXPECT_EQ(*it, 100);

    ++it;
    *it = 200;
    EXPECT_EQ(*it, 200);

    ++it;
    *it = 300;
    EXPECT_EQ(*it, 300);
}

TEST(TestDl_listLib, can_read_iterator_minus_Dl_list) {
    Dl_list<int> l;

    for (int i = 0; i < 3; i++) {
        l.push_back(i + 1);
    }
    auto it = l.end();
    EXPECT_EQ(*it, 3);

    it--;
    EXPECT_EQ(*it, 2);

    it--;
    EXPECT_EQ(*it, 1);
}

TEST(TestDl_listLib, can_write_iterator_minus_Dl_list) {
    Dl_list<int> l;

    for (int i = 0; i < 3; i++) {
        l.push_back((i + 1) * 10);
    }

    auto it = l.end();
    *it = 100;
    EXPECT_EQ(*it, 100);

    --it;
    *it = 200;
    EXPECT_EQ(*it, 200);

    --it;
    *it = 300;
    EXPECT_EQ(*it, 300);
}

//TEST(TestListLib, empty_iterator_DL_list) {
//    Dl_list<int> l;
//    auto a = l.begin();
//    auto b = l.end();
//    EXPECT_EQ(a, b);
//}