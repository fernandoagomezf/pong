
#include "common.h"
#include "color.h"

using std::invalid_argument;
using game::Color;

Color::Color()
    : Color(_minVal, _minVal, _minVal) {

}

Color::Color(int red, int green, int blue)
    : Color(red, green, blue, _maxVal) {
    
}

Color::Color(int red, int green, int blue, int alpha) {
    if (!isValid(red)) {
        throw invalid_argument("Red value not within range.");
    }
    _r = red;
    if (!isValid(green)) {
        throw invalid_argument("Green value not within range.");
    }
    _g = green;
    if (!isValid(blue)) {
        throw invalid_argument("Blue value not within range.");
    }
    _b = blue;
    if (!isValid(alpha)) {
        throw invalid_argument("Alpha value not within range.");
    }
    _a = alpha;
}

Color::Color(const Color& other)
    : Color(other._r, other._g, other._b, other._a) {

}

Color::~Color() {

}

int Color::r() const {
    return _r;
}

int Color::g() const {
    return _g;
}

int Color::b() const {
    return _b;
}

int Color::a() const {
    return _a;
}

bool Color::isValid(int val) {
    return val >= _minVal && val <= _maxVal;
}

Color& Color::operator= (const Color& other) {
    _r = other._r;
    _g = other._g;
    _b = other._b;
    _a = other._a;
    
    return *this;
}

bool Color::operator == (const Color& other) {
    return _r == other._r 
        && _g == other._g
        && _b == other._b
        && _a == other._a;
}

bool Color::operator != (const Color& other) {
    return !(*this == other);
}

Color Color::white() {
    return Color(255, 255, 255);
}

Color Color::black() {
    return Color(0, 0, 0);
}

Color Color::red() {
    return Color(255, 0, 0);
}

Color Color::green() {
    return Color(0, 255, 0);
}

Color Color::blue() {
    return Color(0, 0, 255);
}

Color Color::yellow() {
    return Color(255, 255, 0);
}

Color Color::cyan() {
    return Color(0, 255, 255);
}

Color Color::magenta() {
    return Color(255, 0, 255);
}

Color Color::gray() {
    return Color(128, 128, 128);
}

Color Color::darkRed() {
    return Color(139, 0, 0);
}

Color Color::forestGreen() {
    return Color(34, 139, 34);
}

Color Color::navyBlue() {
    return Color(0, 0, 128);
}

Color Color::gold() {
    return Color(255, 215, 0);
}

Color Color::orange() {
    return Color(255, 165, 0);
}

Color Color::pink() {
    return Color(255, 192, 283);
}

Color Color::purple() {
    return Color(128, 0, 128);
}
