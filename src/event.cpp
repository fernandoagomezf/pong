
#include <typeinfo>
#include <string>
#include "event.h"

using std::string;
using game::Event;

Event::Event() {

}

Event::Event(const Event& other) {

}

Event::~Event() {

}

string Event::type() const {
    return typeid(*this).raw_name();
}

Event& Event::operator= (const Event& other) {
    return *this;
}
