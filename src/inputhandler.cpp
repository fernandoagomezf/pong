
#include <stdexcept>
#include <SDL2/SDL.h>
#include "inputhandler.h"
#include "event.h"
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

void InputHandler::dispatch() {    
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type){
            case SDL_QUIT:
                _bus->publish(Event::QUIT_GAME); break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE: 
                        _bus->publish(Event::QUIT_GAME); break;
                    case SDLK_w: 
                        _bus->publish(Event::PADDLE_UP); break;
                    case SDLK_s: 
                        _bus->publish(Event::PADDLE_DOWN); break;
                    case SDLK_F3:
                        break;
                }
                break;
            case SDL_WINDOWEVENT:
                switch (event.window.event) {
                    case SDL_WINDOWEVENT_CLOSE:
                        _bus->publish(Event::QUIT_GAME); break;
                }
                break;
        }        
    }
}

