#include <iostream>
#include <algorithm>
#include <string>
#include <Windows.h>
#include "point.h"
#include "math.h"

Point::Point(float x, float y) : _x(x), _y(y) {}
Point::Point() : _x(0), _y(0) {}
Point::Point(const Point& other) {
    this->_x = other._x;
    this->_y = other._y;
}

float distance(Point a, Point b) {
    float result = sqrt(pow(b.get_x() - a.get_x(), 2) + pow(b.get_y() - a.get_y(), 2));
    return result;
}

float Point::get_x() const {
    return _x;
}

float Point::get_y() const {
    return _y;
}