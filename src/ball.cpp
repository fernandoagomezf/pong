
#include "common.h"
#include "ball.h"
#include "scene.h"
#include "sceneitem.h"

using std::invalid_argument;
using game::Ball;
using game::Scene;

Ball::Ball()
    : SceneItem() {    
    _velX = 3;
    _velY = 3;
    Dimension dim(15, 15);
    resize(dim);
}

Ball::~Ball() {
    
}

void Ball::reverseX() {
    _velX *= -1;
}

void Ball::update(long delta) {
    SceneItem::update(delta);

    auto pt = point();
    auto dim = dimension();
    auto xpt = pt.x() + _velX;
    auto ypt = pt.y() + _velY;

    Point newpt(xpt, ypt);
    moveTo(newpt);
    
    if (newpt.y() < 0 || newpt.y() > 600 - dim.height()) {
        _velY *= -1;
    }
}

void Ball::render(Scene* scene) {
    SceneItem::render(scene);
    auto pt = point();
    auto dim = dimension();
    scene->drawZone(pt, dim, Color::white());
}

void Ball::reset() {
    Point opt(400, 300);
    moveTo(opt);
    _velX *= -1;
}
