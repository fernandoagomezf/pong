
#include "common.h"
#include "gameapp.h"
#include "ball.h"
#include "paddle.h"
#include "scene.h"
#include "courtscene.h"

using std::runtime_error;
using std::string;
using game::GameApp;
using game::Point;
using game::Dimension;
using game::Scene;
using game::CourtScene;

GameApp::GameApp() {
    SDL_Init(SDL_INIT_VIDEO);
    _scene = new CourtScene();    
    _isRunning = true;

    Point playerPaddlePt(50, 250);
    Point machinePaddlePt(750, 250);
    _playerPaddle = new Paddle();
    _playerPaddle->moveTo(playerPaddlePt);
    _machinePaddle = new Paddle();
    _machinePaddle->moveTo(machinePaddlePt);
    _ball = new Ball();
    _ball->reset();
}

GameApp::~GameApp() {
    delete _playerPaddle;
    delete _machinePaddle;
    delete _ball;
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
        }
    }

    const Uint8* keys = SDL_GetKeyboardState(nullptr);
    if (keys[SDL_SCANCODE_UP]) {
        _playerPaddle->moveUp();
    }
    if (keys[SDL_SCANCODE_DOWN]) { 
        _playerPaddle->moveDown();
    }
}
