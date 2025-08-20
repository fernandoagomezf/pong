
#include <stdexcept>
#include "paddle.h"
#include "vector.h"
#include "scene.h"

using std::invalid_argument;
using game::Paddle;
using game::Vector;

Paddle::Paddle() {
    _speed = 5;
    Vector size(20, 100);
    resize(size);
}

Paddle::~Paddle() {
    
}

void Paddle::update(float delta) {
    SceneItem::update(delta);

    auto pos = position();
    auto sze = size();
    auto newx = pos.x();
    auto newy = pos.y();

    if (newy < 0) { 
        newy = 0;
    }
    if (newy > 600 - sze.y()) {
        newy = 600 - sze.y();
    }

    Vector newpt(newx, newy);
    moveTo(newpt);
}

void Paddle::render(Renderer* renderer) {
    SceneItem::render(renderer);
    
    auto rect = rectangle();
    renderer->draw(rect, Color::white());
}

void Paddle::moveUp() {
    auto pos = position();
    auto newx = pos.x();
    auto newy = pos.y() - _speed;    
    Vector newpt(newx, newy);
    moveTo(newpt);
}

void Paddle::moveDown() {
    auto pos = position();
    auto newx = pos.x();
    auto newy = pos.y() + _speed;    
    Vector newpt(newx, newy);
    moveTo(newpt);
}
