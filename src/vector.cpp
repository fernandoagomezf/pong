
#include "vector.h"
#include <cmath>

using std::sqrt;
using game::Vector;

Vector::Vector() {
    _x = 0.0f;
    _y = 0.0f;
}

Vector::Vector(float x, float y) {
    _x = x;
    _y = y;
}

Vector::Vector(const Vector& other) {
    _x = other._x;
    _y = other._y;
}

Vector::~Vector() {

}

float Vector::x() const {
    return _x;
}

float Vector::y() const {
    return _y;
}

Vector Vector::normalize() const {
    auto x = 0.0f;
    auto y = 0.0f;
    auto len = length();
    if (len > 0.0f) {
        x = _x / len;
        y = _y / len;
    }

    return Vector(x, y);
}

Vector Vector::add(const Vector& other) const {
    return Vector(_x + other._x, _y + other._y);
}

Vector Vector::substract(const Vector& other) const {
    return Vector(_x - other._x, _y - other._y);
}

float Vector::length() const {
    auto xsqr = _x * _x;
    auto ysqr = _y * _y;
    return sqrt(xsqr + ysqr);
}

Vector Vector::scale(float scalar) const {
    auto x = _x * scalar;
    auto y = _y * scalar;

    return Vector(x, y);
}

Vector& Vector::operator= (const Vector& other) {
    _x = other._x;
    _y = other._y;
    return *this;
}

bool Vector::operator== (const Vector& other) const {
    return _x == other._x 
        && _y == other._y;
}

bool Vector::operator!= (const Vector& other) const {
    return !(*this == other);
}