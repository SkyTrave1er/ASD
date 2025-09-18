#include <gtest/gtest.h>
#include "../lib_circle/circle.h"

#define EPSILON 0.000001

TEST(TestCircleLib, can_create_circle) {
    // Arrange
    Point p1(3, 5);
    Circle c1(p1, 10);

    // Act & Assert
    ASSERT_NO_THROW(c1);
}

TEST(TestCircleLib, dist) {
    // Arrange
    Point p1(2, 1);
    Point p2(10, 5);

    // Act & Assert
    ASSERT_NO_THROW(distance(p1, p2));
}

