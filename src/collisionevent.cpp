#include <stdexcept>
#include "collisionevent.h"

using std::invalid_argument;
using game::Event;
using game::CollisionEvent;
using game::SceneItem;

CollisionEvent::CollisionEvent(SceneItem* firstObject, SceneItem* secondObject)
    : Event() {
    if (firstObject == nullptr || secondObject == nullptr) {
        throw invalid_argument("A collision event needs to have two valid scene items.");
    }
    _firstObject = firstObject;
    _secondObject = secondObject;
}

CollisionEvent::CollisionEvent(const CollisionEvent& other)
    : Event(other) {
    _firstObject = other._firstObject;
    _secondObject = other._secondObject;
}

CollisionEvent::~CollisionEvent() {
    _firstObject = nullptr;
    _secondObject = nullptr;
}

SceneItem* CollisionEvent::firstObject() const {
    return _firstObject;
}

SceneItem* CollisionEvent::secondObject() const {
    return _secondObject;
}

CollisionEvent& CollisionEvent::operator= (const CollisionEvent& other) {
    Event::operator=(other);
    _firstObject = other._firstObject;
    _secondObject = other._secondObject;
    return *this;
}