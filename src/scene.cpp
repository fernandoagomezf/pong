
#include "common.h"
#include "scene.h"

using game::Scene;

Scene::Scene()
    : _dimension(800, 600) {
    _window = nullptr;
    _renderer = nullptr;
}

Scene::Scene(SDL_Window* window, SDL_Renderer* renderer)
    : _dimension(800, 600) {
    _window = window;
    _renderer = renderer;
}

Scene::~Scene() {

}

void Scene::load() {
    if (_window == nullptr) {
        auto width = _dimension.width();
        auto height = _dimension.height();
        _window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    }
    if (_renderer == nullptr) {
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    }
}

void Scene::unload() {
    if (_renderer != nullptr) {
        SDL_DestroyRenderer(_renderer);
        _renderer = nullptr;
    }
    if (_window != nullptr) {
        SDL_DestroyWindow(_window);
        _window = nullptr;
    }
}

void Scene::drawZone(const Point& pt, const Dimension& dim, const Color& color) {    
    SDL_Rect rect = { 
        pt.x(), pt.y(), dim.width(), dim.height()
    };
    SDL_SetRenderDrawColor(_renderer, color.r(), color.g(), color.b(), color.a());
    SDL_RenderFillRect(_renderer, &rect);
}

void Scene::clear() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); 
    SDL_RenderClear(_renderer);
}

void Scene::show() {
    SDL_RenderPresent(_renderer);
}