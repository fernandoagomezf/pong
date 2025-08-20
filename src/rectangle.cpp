
#include "rectangle.h"
#include <stdexcept>
#include <SDL2/SDL.h>

using std::invalid_argument;
using game::Rectangle;
using game::Vector;

Rectangle::Rectangle(float x, float y, float width, float height) {
    if (width < 0.0f || height < 0.0f) {
        throw invalid_argument("The dimensions cannot be negative.");
    }
    _x = x;
    _y = y;
    _width = width;
    _height = height;
}
            
Rectangle::Rectangle(const Vector& position, const Vector& size) {
    _x = position.x();
    _y = position.y();
    _width = size.x();
    _height = size.y();
}

Rectangle::Rectangle(const Rectangle& other) {
    _x = other._x;
    _y = other._y;
    _width = other._width;
    _height = other._height;
}

Rectangle::~Rectangle() {

}

float Rectangle::x() const {
    return _x;
}

float Rectangle::y() const {
    return _y;
}

float Rectangle::width() const {
    return _width;
}

float Rectangle::height() const {
    return _height;
}

Vector Rectangle::originPosition() const {
    return Vector(_x, _y);
}

Vector Rectangle::endPosition() const {
    return Vector(_x + _width, _y + _height);
}

Vector Rectangle::size() const {
    return Vector(_width, _height);
}

bool Rectangle::intersects(const Rectangle& other) const {
    SDL_Rect thisRect {
        static_cast<int>(_x), 
        static_cast<int>(_y), 
        static_cast<int>(_width),
        static_cast<int>(_height)
    };
    SDL_Rect otherRect {
        static_cast<int>(other._x), 
        static_cast<int>(other._y), 
        static_cast<int>(other._width), 
        static_cast<int>(other._height)
    };
    
    auto result = SDL_HasIntersection(&thisRect, &otherRect);
    
    return result == SDL_TRUE;
}

Rectangle& Rectangle::operator= (const Rectangle& other) {
    _x = other._x;
    _y = other._y;
    _width = other._width;
    _height = other._height;
    
    return *this;
}

bool Rectangle::operator== (const Rectangle& other) const {
    return _x == other._x 
        && _y == other._y 
        && _width == other._width
        && _height == other._height;
}

bool Rectangle::operator!= (const Rectangle& other) const {
    return !(*this == other);
}