#include "dimension.h"

using game::Dimension;

Dimension::Dimension(int width, int height) {
    _width = width;
    _height = height;
}

Dimension::Dimension(const Dimension& other) {
    _width = other._width;
    _height = other._height;
}

Dimension::~Dimension() {

}

int Dimension::width() const {
    return _width;
}

int Dimension::height() const {
    return _height;
}

Dimension& Dimension::operator= (const Dimension& other) {
    _width = other._width;
    _height = other._height;
    return *this;
}

bool Dimension::operator== (const Dimension& other) const {
    return _width == other._width && _height == other._height;
}

bool Dimension::operator!= (const Dimension& other) const {
    return !(*this == other);
}
