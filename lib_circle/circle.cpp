#include "circle.h"
#include <iostream>

Circle::Circle(Point p, float r) : _p(p), _r(r) {
    if (_r <= 0) {
        throw std::invalid_argument("cant minus");
    }
}
Circle::Circle() : _p(Point()), _r(0.1) {}
Circle::Circle(const Circle& other) {
    this->_p = other._p;
    this->_r = other._r;
}
float Circle::get_r() {
    return _r;
}

Point Circle::get_p() {
    return _p;
}
int type_of(Circle c1, Circle c2) {

    if (distance(c1.get_p(), c2.get_p()) == (c1.get_r() + c2.get_r())) {
        return 1;
    }
    else if ((distance(c1.get_p(), c2.get_p()) < (c1.get_r() + c2.get_r()))
        && (distance(c1.get_p(), c2.get_p()) > abs(c1.get_r() - c2.get_r()))) {
        return 2;
    }
    else if (distance(c1.get_p(), c2.get_p()) > (c1.get_r() + c2.get_r())) {
        return 3;
    }
    else {
        return 4;
    }
}