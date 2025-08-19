
#include "common.h"
#include "gameapp.h"
#include "ball.h"
#include "paddle.h"
#include "scene.h"
#include "courtscene.h"
#include "eventbus.h"
#include "inputhandler.h"
#include "renderer.h"
#include <SDL2/SDL.h>

using std::runtime_error;
using std::string;
using game::GameApp;
using game::Point;
using game::Dimension;
using game::Scene;
using game::CourtScene;
using game::InputHandler;
using game::EventBus;
using game::Renderer;

GameApp::GameApp() {
    SDL_Init(SDL_INIT_VIDEO);
    _renderer = new Renderer();
    _bus = new EventBus();
    _handler = new InputHandler(_bus);
    _scene = new CourtScene(_renderer, _bus);    
    _isRunning = true;

    _bus->subscribe(Event::QUIT_GAME, [this]() {
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

    _renderer->create("Tollan Pong", Dimension(800, 600));

    _scene->load();
    while (_isRunning) {
        auto currentTicks = SDL_GetTicks();
        auto delta = currentTicks - lastTicks;
        lastTicks = currentTicks;

        _handler->dispatch();
        _scene->update(delta);
        _scene->render(); 

        SDL_Delay(16);
    }
    _scene->unload();
}

void GameApp::quit() {
    _isRunning = false;
}
