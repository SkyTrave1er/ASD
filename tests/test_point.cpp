#include <gtest/gtest.h>
#include "../lib_point/point.h"

#define EPSILON 0.000001

TEST(TestPointLib, can_create_point) {
    // Arrange
    Point p1(3, 5);

    // Act & Assert
    ASSERT_NO_THROW(p1);
}

TEST(TestPointLib, dist) {
    // Arrange
    Point p1(2, 1);
    Point p2(10, 5);

    // Act & Assert
    ASSERT_NO_THROW(distance(p1, p2));
}

TEST(TestPointLib, null_dist) {
    // Arrange
    Point p1(2, 1);
    Point p2(2, 1);

    // Act & Assert
    EXPECT_EQ(distance(p1, p2), 0);
}

TEST(TestPointLib, copy_constructor) {
    // Arrange
    Point p1(2, 1);
    Point p2(p1);

    // Act & Assert
    EXPECT_EQ(p1.get_x(), p2.get_x());
    EXPECT_EQ(p1.get_y(), p2.get_y());
}