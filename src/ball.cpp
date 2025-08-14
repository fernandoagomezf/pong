
#include "common.h"
#include "ball.h"

using std::invalid_argument;
using game::Ball;

Ball::Ball(SDL_Renderer* renderer, int x, int y) {
    if (renderer == nullptr) {
        throw invalid_argument("Renderer cannot be null.");
    }

    _renderer = renderer;
    _velX = 3;
    _velY = 3;
    _rect = {x, y, 15, 15}; 

}

Ball::~Ball() {
    
}

void Ball::reverseX() {
    _velX *= -1;
}

SDL_Rect Ball::getRect() const {
    return _rect;
}

void Ball::update() {
    _rect.x += _velX;
    _rect.y += _velY;
    if (_rect.y < 0 || _rect.y > 600 - _rect.h) {
        _velY *= -1;
    }
}

void Ball::render() {
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(_renderer, &_rect);
}

void Ball::reset() {
    _rect.x = 400;
    _rect.y = 300;
    _velX *= -1;
}
