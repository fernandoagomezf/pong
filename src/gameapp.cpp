
#include "common.h"
#include "gameapp.h"
#include "ball.h"
#include "paddle.h"
#include "scene.h"

using std::runtime_error;
using std::string;
using game::GameApp;
using game::Point;
using game::Dimension;
using game::Scene;

GameApp::GameApp() {
    SDL_Init(SDL_INIT_VIDEO);
    _scene = new Scene();    
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
    _scene->load();
    while (_isRunning) {
        handleEvents();
        update();
        render();
        SDL_Delay(16);  // ~60 FPS
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

void GameApp::update() {
    _ball->update(0);
    _playerPaddle->update(0);
    _machinePaddle->update(0);

    auto ballPt = _ball->point();
    auto ballDim = _ball->dimension();
    auto machinePaddlePt = _machinePaddle->point();
    auto machinePaddleDim = _machinePaddle->dimension();
    auto playerPaddlePt = _playerPaddle->point();
    auto playerPaddleDim = _playerPaddle->dimension();
    
    SDL_Rect ballRect = { 
        ballPt.x(), 
        ballPt.y(), 
        ballDim.width(), 
        ballDim.height() 
    };
    SDL_Rect machineRect = {
        machinePaddlePt.x(), 
        machinePaddlePt.y(), 
        machinePaddleDim.width(), 
        machinePaddleDim.height()
    };
    SDL_Rect playerRect = {
        playerPaddlePt.x(), 
        playerPaddlePt.y(), 
        playerPaddleDim.width(),
        playerPaddleDim.height()
    };

    if (machineRect.y + machineRect.h / 2 < ballPt.y()) {
        _machinePaddle->moveDown();
    } else {
        _machinePaddle->moveUp();
    }


    if (SDL_HasIntersection(&ballRect, &playerRect) ||
        SDL_HasIntersection(&ballRect, &machineRect)) {
        _ball->reverseX();
    }
    if (ballPt.x() < 0 || ballPt.x() > 800) {
        _ball->reset();
    }
}

void GameApp::render() {
    _scene->clear();

    _playerPaddle->render(_scene);
    _machinePaddle->render(_scene);
    _ball->render(_scene);

    _scene->show();
}
