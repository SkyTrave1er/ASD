#pragma once


class Point {
    float _x;
    float _y;
public:
    Point();
    Point(float x, float y);
    Point(const Point& other);
    float get_x() const;
    float get_y() const;
};

float distance(Point a, Point b);
