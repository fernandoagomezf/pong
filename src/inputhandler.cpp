
#include <stdexcept>
#include <SDL2/SDL.h>
#include "inputhandler.h"
#include "eventbus.h"
#include "quitevent.h"
#include "paddlemovedevent.h"
#include "paddledirection.h"

using std::invalid_argument;
using game::QuitEvent;
using game::EventBus;
using game::InputHandler;
using game::PaddleMovedEvent;
using game::PaddleDirection;

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
                _bus->publish(new QuitEvent()); break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE: 
                        _bus->publish(new QuitEvent()); break;
                    case SDLK_w: 
                        _bus->publish(new PaddleMovedEvent(PaddleDirection::UP)); break;
                    case SDLK_s: 
                        _bus->publish(new PaddleMovedEvent(PaddleDirection::DOWN)); break;
                    case SDLK_F3:
                        break;
                }
                break;
            case SDL_WINDOWEVENT:
                switch (event.window.event) {
                    case SDL_WINDOWEVENT_CLOSE:
                        _bus->publish(new QuitEvent()); break;
                }
                break;
        }        
    }
}

