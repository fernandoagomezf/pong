
#include "renderer.h"
#include "dimension.h"
#include <SDL2/SDL.h>

using std::make_unique;
using std::string;
using std::runtime_error;
using game::Dimension;
using game::Renderer;

struct Renderer::Impl {
    SDL_Window* window;
    SDL_Renderer* renderer;
};

Renderer::Renderer() {
    _impl = make_unique<Impl>();
}

Renderer::~Renderer() {

}

bool Renderer::isCreated() const {
    return _impl->window != nullptr && _impl->renderer != nullptr;
}

void Renderer::create(const string& title, const Dimension& dimension){
    if (isCreated()) {
        throw runtime_error("The renderer has already been created.");
    }
    
    auto width = dimension.width();
    auto height = dimension.height();
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

void Renderer::draw(const Point& pt, const Dimension& dim, const Color& color) {
    SDL_Rect rect = { 
        pt.x(), pt.y(), dim.width(), dim.height()
    };
    SDL_SetRenderDrawColor(_impl->renderer, color.r(), color.g(), color.b(), color.a());
    SDL_RenderFillRect(_impl->renderer, &rect);
}

void Renderer::show() {
    SDL_RenderPresent(_impl->renderer);
}