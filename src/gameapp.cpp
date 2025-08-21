
#include <stdexcept>
#include <algorithm>
#include <string>
#include <SDL2/SDL.h>
#include "gameapp.h"
#include "courtscene.h"
#include "quitevent.h"

using std::min;
using std::runtime_error;
using std::string;
using game::GameApp;
using game::CourtScene;
using game::InputHandler;
using game::EventBus;
using game::Renderer;
using game::QuitEvent;
using game::Vector;

GameApp::GameApp() {
    _renderer = new Renderer();
    _bus = new EventBus();
    _handler = new InputHandler(_bus);
    _scene = new CourtScene(_bus);    
    _isRunning = true;

    _bus->subscribe<QuitEvent>([this](const Event*) {
        quit();
    });
}

GameApp::~GameApp() {
    delete _scene;
    delete _handler;
    delete _bus;
    delete _renderer;
    SDL_Quit();
}

void GameApp::run() {
    uint32_t lastTicks = 0;

    _renderer->create("Tollan Pong", Vector(800, 600));

    _scene->load();
    while (_isRunning) {
        auto currentTicks = SDL_GetTicks();
        auto delta = (currentTicks - lastTicks) / 1000.0f;
        lastTicks = currentTicks;

        delta = min(delta, 0.1f);

        _handler->dispatch();
        _scene->update(delta);
        _scene->render(_renderer); 
    }
    _scene->unload();
}

void GameApp::quit() {
    _isRunning = false;
}
