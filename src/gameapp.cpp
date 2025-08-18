
#include "common.h"
#include "gameapp.h"
#include "ball.h"
#include "paddle.h"
#include "scene.h"
#include "courtscene.h"
#include "eventbus.h"
#include "inputhandler.h"

using std::runtime_error;
using std::string;
using game::GameApp;
using game::Point;
using game::Dimension;
using game::Scene;
using game::CourtScene;
using game::InputHandler;
using game::EventBus;

GameApp::GameApp() {
    SDL_Init(SDL_INIT_VIDEO);
    _bus = new EventBus();
    _handler = new InputHandler(_bus);
    _scene = new CourtScene(_bus);    
    _isRunning = true;
}

GameApp::~GameApp() {
    delete _scene;
    delete _handler;
    delete _bus;
    SDL_Quit();
}

void GameApp::run() {
    uint32_t lastTicks = 0;

    _scene->load();
    while (_isRunning) {
        auto currentTicks = SDL_GetTicks();
        auto delta = currentTicks - lastTicks;
        lastTicks = currentTicks;

        handleEvents();
        _scene->update(delta);
        _scene->render(); 

        SDL_Delay(16);
    }
    _scene->unload();
}

void GameApp::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            _isRunning = false;
        } else {
            _handler->handle(event);
        }
    }
}
