#include "common.h"
#include "sceneitem.h"

using std::invalid_argument;
using game::SceneItem;
using game::Renderer;
using game::Point;
using game::Dimension;

SceneItem::SceneItem()
    : _rectangle(0, 0, 0, 0) {
    
}

SceneItem::~SceneItem() {

}

Point SceneItem::point() const {
    return _rectangle.getOriginPoint();
}

Dimension SceneItem::dimension() const {
    return _rectangle.getDimension();
}

void SceneItem::moveTo(const Point& point) {
    auto dim = _rectangle.getDimension();
    _rectangle = Rectangle(point, dim);
}

void SceneItem::redim(const Dimension& dimension) {    
    auto pt = _rectangle.getOriginPoint();
    _rectangle = Rectangle(pt, dimension);
}

void SceneItem::update(long delta) {
    if (delta < 0) {
        throw invalid_argument("The update delta for a scene item cannot be a negative number.");
    }
}

void SceneItem::render(Renderer* renderer) {
    if (renderer == nullptr) {
        throw invalid_argument("Cannot render a scene item with an invalid renderer.");
    }
}