#include "../lib_point/point.h"

class Circle {
    Point _p;
    float _r;
public:
    Circle(Point p, float r);
    Circle();
    Circle(const Circle& other);
    float get_r();
    Point get_p();
};

int type_of(Circle c1, Circle c2);