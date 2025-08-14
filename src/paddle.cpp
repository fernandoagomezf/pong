#include "common.h"
#include "paddle.h"

using std::invalid_argument;
using game::Paddle;

Paddle::Paddle(SDL_Renderer* renderer, int x, int y) {
    if (renderer == nullptr) {
        throw invalid_argument("Renderer cannot be null.");
    }

    _renderer = renderer;
    _speed = 5;
    _rect = { x, y, 20, 100 };
}

Paddle::~Paddle() {
    
}

SDL_Rect Paddle::getRect() const {
    return _rect;
}

void Paddle::update() {
    if (_rect.y < 0) { 
        _rect.y = 0;
    }
    if (_rect.y > 600 - _rect.h) {
        _rect.y = 600 - _rect.h;
    }
}

void Paddle::render() {
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(_renderer, &_rect);
}

void Paddle::moveUp() {
    _rect.y -= _speed;    
}

void Paddle::moveDown() {
    _rect.y += _speed;
}
