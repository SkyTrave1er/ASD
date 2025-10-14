#include <gtest/gtest.h>
#include "../lib_queue/queue.h"

TEST(TestQueueLib, can_create_queue) {
    Queue<int> q(10);
    EXPECT_EQ(q.get_count(), 0);
    EXPECT_EQ(q.get_size(), 10);
    EXPECT_EQ(q.get_head(), 0);
    EXPECT_EQ(q.get_tail(), 0);
}

TEST(TestQueueLib, can_copy_queue) {
    Queue<int> q1(4);
    q1.push(5);
    q1.push(8);

    Queue<int> q2(q1);

    EXPECT_EQ(q2.get_count(), 2);
    EXPECT_EQ(q2.get_tail(), 2);
    EXPECT_EQ(q2.get_head(), 0);
    EXPECT_EQ(q2.tail(), 8);
    EXPECT_EQ(q2.head(), 5);
    EXPECT_EQ(q2.get_size(), 4);
}

TEST(TestQueueLib, can_push_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.push(1);

    EXPECT_EQ(q.head(), 5);
    EXPECT_EQ(q.tail(), 1);
    EXPECT_EQ(q.get_count(), 3);
}

TEST(TestQueueLib, throw_when_push_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.push(90);
    q.push(14);

    EXPECT_ANY_THROW(q.push(1));
}

TEST(TestQueueLib, can_pop_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.push(7);

    q.pop();
    q.pop();

    EXPECT_EQ(q.tail(), 7);
    EXPECT_EQ(q.head(), 7);
    EXPECT_EQ(q.get_count(), 1);
    EXPECT_EQ(q.get_head(), 2);
    EXPECT_EQ(q.get_tail(), 3);
}

TEST(TestQueueLib, throw_when_pop_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.pop();
    q.pop();

    EXPECT_ANY_THROW(q.pop());
}

TEST(TestQueueLib, can_head_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.pop();
    q.push(7);
    q.pop();

    EXPECT_EQ(q.get_head(), 2);
    EXPECT_EQ(q.head(), 7);
}

TEST(TestQueueLib, throw_when_head_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.pop();
    q.pop();

    EXPECT_ANY_THROW(q.head());
}

TEST(TestQueueLib, can_tail_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.pop();
    q.push(7);
    q.pop();

    EXPECT_EQ(q.get_tail(), 3);
    EXPECT_EQ(q.tail(), 7);
}

TEST(TestQueueLib, throw_when_tail_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.pop();
    q.pop();

    EXPECT_ANY_THROW(q.tail());
}

TEST(TestQueueLib, empty_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.pop();
    q.pop();

    EXPECT_EQ(q.is_empty(), 1);
}

TEST(TestQueueLib, throw_when_empty_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.pop();

    EXPECT_EQ(q.is_empty(), 0);
}

TEST(TestQueueLib, full_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.push(22);
    q.push(99);

    EXPECT_EQ(q.is_full(), 1);
}

TEST(TestQueueLib, throw_when_full_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);

    EXPECT_EQ(q.is_full(), 0);
}

TEST(TestQueueLib, can_clear_queue) {
    Queue<int> q(4);
    q.push(5);
    q.push(8);
    q.clear();

    EXPECT_EQ(q.get_head(), 0);
    EXPECT_EQ(q.get_tail(), 0);
    EXPECT_EQ(q.get_count(), 0);
}
