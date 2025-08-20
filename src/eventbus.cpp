
#include "event.h"
#include "eventbus.h"

using std::function;
using game::Event;
using game::EventBus;

EventBus::EventBus() {

}

EventBus::~EventBus() {

}

void EventBus::subscribe(Event event, function<void()> callback) {
    _subscribers[event].push_back(callback);
}

void EventBus::clear(Event event) {
    _subscribers[event].clear();
}

void EventBus::publish(Event event) {
    for (auto& callback : _subscribers[event]) {
        callback();
    }
}
