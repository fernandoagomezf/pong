
#include <stdexcept>
#include "ball.h"

using std::invalid_argument;
using game::Ball;
using game::Renderer;

Ball::Ball()
    : SceneItem() {    
    _direction = Vector(1, 1).normalize();
    _speed = 300;
    Vector dim(15, 15);
    resize(dim);
}

Ball::~Ball() {
    
}

void Ball::reverseX() {
    //_xDir *= -1;
}

void Ball::reverseY() {
    //_yDir *= -1;
}

void Ball::update(float delta) {
    SceneItem::update(delta);

    float screenWidth = 800;
    float screenHeight = 600;
    Vector sze = size();
    Vector movement = _direction.scale(_speed * delta);
    Vector newPosition = position().add(movement);

    if (newPosition.x() < 0.f) {
        newPosition = Vector(0.f, newPosition.y());
        _direction = Vector(-_direction.x(), _direction.y());
    } else if (newPosition.x() > screenWidth - sze.x()) {
        newPosition = Vector(screenWidth - sze.x(), _direction.y());
        _direction = Vector(-_direction.x(), _direction.y());
    }

    if (newPosition.y() < 0.f) {
        newPosition = Vector(newPosition.x(), 0.f);
        _direction = Vector(_direction.x(), -_direction.y());
    } else if (newPosition.y() > screenHeight - sze.y()) {
        newPosition = Vector(newPosition.x(), screenHeight - sze.y());
        _direction = Vector(_direction.x(), -_direction.y());
    }

    moveTo(newPosition);
}

void Ball::render(Renderer* renderer) {
    SceneItem::render(renderer);
    auto rect = rectangle();
    renderer->draw(rect, Color::white());
}

void Ball::reset() {
    Vector opt(400, 300);
    moveTo(opt);
    reverseX();
}
