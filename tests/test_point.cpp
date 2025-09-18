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