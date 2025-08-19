
#include "common.h"
#include "rectangle.h"
#include "dimension.h"
#include "point.h"
#include <SDL2/SDL.h>

using std::invalid_argument;
using game::Rectangle;
using game::Dimension;
using game::Point;

Rectangle::Rectangle(int x, int y, int width, int height) {
    if (width < 0 || height < 0) {
        throw invalid_argument("The dimensions cannot be negative.");
    }
    _x = x;
    _y = y;
    _width = width;
    _height = height;
}
            
Rectangle::Rectangle(const Point& point, const Dimension& dimension) {
    _x = point.x();
    _y = point.y();
    _width = dimension.width();
    _height = dimension.height();
}

Rectangle::Rectangle(const Rectangle& other) {
    _x = other._x;
    _y = other._y;
    _width = other._width;
    _height = other._height;
}

Rectangle::~Rectangle() {

}

int Rectangle::x() const {
    return _x;
}

int Rectangle::y() const {
    return _y;
}

int Rectangle::width() const {
    return _width;
}

int Rectangle::height() const {
    return _height;
}

Point Rectangle::getOriginPoint() const {
    return Point(_x, _y);
}

Point Rectangle::getEndPoint() const {
    return Point(_x + _width, _y + _height);
}

Dimension Rectangle::getDimension() const {
    return Dimension(_width, _height);
}

bool Rectangle::intersects(const Rectangle& other) const {
    SDL_Rect thisRect {
        _x, 
        _y, 
        _width, 
        _height
    };
    SDL_Rect otherRect {
        other._x, 
        other._y, 
        other._width, 
        other._height
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