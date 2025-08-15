#include "point.h"

using game::Point;

Point::Point(int x, int y) {
    _x = x;
    _y = y;
}

Point::Point(const Point& other) {
    _x = other._x;
    _y = other._y;
}

Point::~Point() {

}

int Point::x() const {
    return _x;
}

int Point::y() const {
    return _y;
}

Point& Point::operator= (const Point& other) {
    _x = other._x;
    _y = other._y;
    return *this;
}

bool Point::operator== (const Point& other) const {
    return _x == other._x && _y == other._y;
}

bool Point::operator!= (const Point& other) const {
    return !(*this == other);
}
