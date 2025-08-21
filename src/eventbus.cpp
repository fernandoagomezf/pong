#include <stdexcept>
#include "event.h"
#include "eventbus.h"

using std::invalid_argument;
using std::function;
using std::string;
using game::Event;
using game::EventBus;

EventBus::EventBus() {

}

EventBus::~EventBus() {

}

void EventBus::subscribe(const string& eventType, EventBus::Callback callback) {
    _subscribers[eventType].push_back(callback);
}

void EventBus::publish(Event* event) {
    if (event == nullptr) {
        throw invalid_argument("Cannot publish an invalid event.");
    }
    
    auto eventType = event->type();
    for (auto& callback : _subscribers[eventType]) {
        callback(event);
    }
    delete event;
}

void EventBus::clear(const string& eventType) {
    _subscribers[eventType].clear();
}