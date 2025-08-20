#include <stdexcept>
#include "sceneitem.h"

using std::invalid_argument;
using game::SceneItem;
using game::Renderer;
using game::Vector;
using game::Rectangle;

SceneItem::SceneItem()
    : _position(0.f, 0.f), _size(0.f, 0.f) {
    
}

SceneItem::~SceneItem() {

}

Vector SceneItem::position() const {
    return _position;
}

Vector SceneItem::size() const {
    return _size;
}

Rectangle SceneItem::rectangle() const {
    return Rectangle(_position, _size);
}

void SceneItem::moveTo(const Vector& newPosition) {
    _position = newPosition;
}

void SceneItem::resize(const Vector& newSize) {    
    _size = newSize;
}

void SceneItem::update(float delta) {
    if (delta < 0) {
        throw invalid_argument("The update delta for a scene item cannot be a negative number.");
    }
}

void SceneItem::render(Renderer* renderer) {
    if (renderer == nullptr) {
        throw invalid_argument("Cannot render a scene item with an invalid renderer.");
    }
}