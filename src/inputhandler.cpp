
#include "common.h"
#include "inputhandler.h"
#include "eventbus.h"

using std::invalid_argument;
using game::Event;
using game::EventBus;
using game::InputHandler;

InputHandler::InputHandler(EventBus* bus) {
    if (bus == nullptr){
        throw invalid_argument("The event bus is required for the input handler.");
    }
    _bus = bus;
}

InputHandler::~InputHandler() {
    _bus = nullptr;
}

void InputHandler::handle(const SDL_Event& event) {    
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w: _bus->publish(Event::PADDLE_UP); break;
            case SDLK_s: _bus->publish(Event::PADDLE_DOWN); break;
        }
    }
}

