#include "common.h"
#include "sceneitem.h"

using std::invalid_argument;
using game::SceneItem;
using game::Scene;
using game::Point;
using game::Dimension;

SceneItem::SceneItem()
    : _point(0, 0), _dimension(0, 0) {    
    
}

SceneItem::~SceneItem() {

}

Point SceneItem::point() const {
    return _point;
}

Dimension SceneItem::dimension() const {
    return _dimension;
}

void SceneItem::moveTo(const Point& point) {
    if (!isValidPoint(point)) {
        throw invalid_argument("Cannot move to an invalid point.");
    }
    _point = point;
}

void SceneItem::resize(const Dimension& dimension) {
    if (!isValidDimension(dimension)) {
        throw invalid_argument("Cannot resize to an invalid dimension.");
    }
    _dimension = dimension;
}

bool SceneItem::isValidPoint(const Point& value) {
    return true; // any point is valid.
}

bool SceneItem::isValidDimension(const Dimension& value) {
    return value.width() > 0 && value.height() > 0; //any dim is valid, just no negative values
}

void SceneItem::update(long delta) {
    if (delta < 0) {
        throw invalid_argument("The update delta for a scene item cannot be a negative number.");
    }
}

void SceneItem::render(Scene* scene) {
    if (scene == nullptr) {
        throw invalid_argument("Cannot render a scene item with an invalid renderer.");
    }
}