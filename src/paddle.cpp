#include "common.h"
#include "paddle.h"
#include "point.h"
#include "dimension.h"
#include "scene.h"
#include "sceneitem.h"

using std::invalid_argument;
using game::Paddle;
using game::Dimension;
using game::Point;

Paddle::Paddle() {
    _speed = 5;
    Dimension dim(20, 100);
    redim(dim);
}

Paddle::~Paddle() {
    
}

void Paddle::update(long delta) {
    SceneItem::update(delta);

    auto pt = point();
    auto dim = dimension();
    auto newx = pt.x();
    auto newy = pt.y();

    if (newy < 0) { 
        newy = 0;
    }
    if (newy > 600 - dim.height()) {
        newy = 600 - dim.height();
    }
    Point newpt(newx, newy);
    moveTo(newpt);
}

void Paddle::render(Renderer* renderer) {
    SceneItem::render(renderer);
    
    auto pt = point();
    auto dim = dimension();
    renderer->draw(pt, dim, Color::white());
}

void Paddle::moveUp() {
    auto pt = point();
    auto newx = pt.x();
    auto newy = pt.y() - _speed;    
    Point newpt(newx, newy);
    moveTo(newpt);
}

void Paddle::moveDown() {
    auto pt = point();
    auto newx = pt.x();
    auto newy = pt.y() + _speed;    
    Point newpt(newx, newy);
    moveTo(newpt);
}
