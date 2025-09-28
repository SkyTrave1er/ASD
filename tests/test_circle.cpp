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

TEST(TestCircleLib, throw_when_minus_radius) {
    // Arrange
    Point p1(2, 1);
    // Act & Assert
    ASSERT_ANY_THROW(Circle c1(p1, -5));
}

TEST(TestCircleLib, circles_touch) {
    // Arrange
    Point p1(2, 1);
    Circle c1(p1, 3);

    Point p2(6, 4);
    Circle c2(p2, 2);

    // Act & Assert
    EXPECT_EQ(type_of(c1, c2), 1);
}

TEST(TestCircleLib, circles_cross) {
    // Arrange
    Point p1(-1, 3);
    Circle c1(p1, 4);

    Point p2(2, -1);
    Circle c2(p2, 3);

    // Act & Assert
    EXPECT_EQ(type_of(c1, c2), 2);
}

TEST(TestCircleLib, circles_dont_touch) {
    // Arrange
    Point p1(10, -5);
    Circle c1(p1, 2);

    Point p2(15, 3);
    Circle c2(p2, 4);

    // Act & Assert
    EXPECT_EQ(type_of(c1, c2), 3);
}

TEST(TestCircleLib, circles_one_in_another) {
    // Arrange
    Point p1(4, 4);
    Circle c1(p1, 6);

    Point p2(5, 3);
    Circle c2(p2, 1);

    // Act & Assert
    EXPECT_EQ(type_of(c1, c2), 4);
}

TEST(TestCircleLib, copy_constructor) {
    // Arrange
    Point p1(7, 4);
    Circle c1(p1, 12);

    Circle c2(c1);

    // Act & Assert
    EXPECT_EQ(c2.get_p().get_x(), c1.get_p().get_x());
    EXPECT_EQ(c2.get_p().get_y(), c1.get_p().get_y());
    EXPECT_EQ(c2.get_r(), c1.get_r());
}

