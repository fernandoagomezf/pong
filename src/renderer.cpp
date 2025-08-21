
#include <SDL2/SDL.h>
#include <stdexcept>
#include "renderer.h"

using std::make_unique;
using std::string;
using std::runtime_error;
using game::Vector;
using game::Renderer;

struct Renderer::impl {
    SDL_Window* window;
    SDL_Renderer* renderer;
};

Renderer::Renderer() {
    _impl = make_unique<impl>();
}

Renderer::~Renderer() {

}

bool Renderer::isCreated() const {
    return _impl->window != nullptr && _impl->renderer != nullptr;
}

void Renderer::create(const string& title, const Vector& size){
    if (isCreated()) {
        throw runtime_error("The renderer has already been created.");
    }
    
    auto width = static_cast<int>(size.x());
    auto height = static_cast<int>(size.y());
    _impl->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    _impl->renderer = SDL_CreateRenderer(_impl->window, -1, SDL_RENDERER_ACCELERATED);
}

void Renderer::ensureCreated() const {
    if (!isCreated()) {
        throw runtime_error("A renderer has not been created yet.");
    }
}

void Renderer::clear() {
    ensureCreated();
    SDL_SetRenderDrawColor(_impl->renderer, 0, 0, 0, 255); 
    SDL_RenderClear(_impl->renderer);
}

void Renderer::draw(const Rectangle& rectangle, const Color& color) {
    SDL_Rect rect = { 
        static_cast<int>(rectangle.x()), 
        static_cast<int>(rectangle.y()), 
        static_cast<int>(rectangle.width()), 
        static_cast<int>(rectangle.height())
    };
    SDL_SetRenderDrawColor(_impl->renderer, color.r(), color.g(), color.b(), color.a());
    SDL_RenderFillRect(_impl->renderer, &rect);
}

void Renderer::show() {
    SDL_RenderPresent(_impl->renderer);
}