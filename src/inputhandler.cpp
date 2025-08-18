
#include "common.h"
#include "inputhandler.h"
#include "eventbus.h"
#include <SDL2/SDL.h>

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

void InputHandler::dispatch() {    
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.key.keysym.sym) {
            case SDL_QUIT: 
                _bus->publish(Event::QUIT_GAME); break;
            case SDLK_w: 
                _bus->publish(Event::PADDLE_UP); break;
            case SDLK_s: 
            _bus->publish(Event::PADDLE_DOWN); break;
        }
    }
}

