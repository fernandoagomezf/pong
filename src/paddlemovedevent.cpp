
#include "paddlemovedevent.h"

using game::Event;
using game::PaddleMovedEvent;
using game::PaddleDirection;

PaddleMovedEvent::PaddleMovedEvent(const PaddleDirection& direction)
    : Event() {
    _direction = direction;
}

PaddleMovedEvent::PaddleMovedEvent(const PaddleMovedEvent& other)
    : Event(other) {
    _direction = other._direction;
}

PaddleMovedEvent::~PaddleMovedEvent() {

}

PaddleDirection PaddleMovedEvent::direction() const {
    return _direction;
}

PaddleMovedEvent& PaddleMovedEvent::operator= (const PaddleMovedEvent& other) {
    Event::operator=(other);
    _direction = other._direction;
    return *this;
}