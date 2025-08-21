#include "quitevent.h"

using game::Event;
using game::QuitEvent;

QuitEvent::QuitEvent()
    : Event() {

}

QuitEvent::QuitEvent(const QuitEvent& other)
    : Event(other) {

}

QuitEvent::~QuitEvent() {

}

QuitEvent& QuitEvent::operator= (const QuitEvent& other) {
    Event::operator=(other); 
    return *this;
}