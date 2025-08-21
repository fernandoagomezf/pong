#include <stdexcept>
#include "boundarycollisionevent.h"

using std::invalid_argument;
using game::Event;
using game::BoundaryCollisionEvent;
using game::Edge;
using game::SceneItem;

BoundaryCollisionEvent::BoundaryCollisionEvent(SceneItem* object, const Edge& edge)
    : Event() {
    if (object == nullptr) {
        throw invalid_argument("A boundary collision event needs to have one valid scene item.");
    }
    
    _object = object;
    _edge = edge;
}

BoundaryCollisionEvent::BoundaryCollisionEvent(const BoundaryCollisionEvent& other) 
    : Event(other) {
    _object = other._object;
    _edge = other._edge;
}

BoundaryCollisionEvent::~BoundaryCollisionEvent() {
    _object = nullptr;
}

SceneItem* BoundaryCollisionEvent::object() const {
    return _object;
}

Edge BoundaryCollisionEvent::edge() const {
    return _edge;
}

BoundaryCollisionEvent& BoundaryCollisionEvent::operator= (const BoundaryCollisionEvent& other) {
    Event::operator=(other);
    _object = other._object;
    _edge = other._edge;
    return *this;
}
