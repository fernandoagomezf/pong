
#include "common.h"
#include "gameapp.h"
#include "ball.h"
#include "paddle.h"

using std::runtime_error;
using std::string;
using game::GameApp;

GameApp::GameApp() {
    SDL_Init(SDL_INIT_VIDEO);
    _window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    _isRunning = true;

    _playerPaddle = new Paddle(_renderer, 50, 250);
    _machinePaddle = new Paddle(_renderer, 750, 250);
    _ball = new Ball(_renderer, 400, 300);
}

GameApp::~GameApp() {
    delete _playerPaddle;
    delete _machinePaddle;
    delete _ball;
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void GameApp::run() {
    while (_isRunning) {
        handleEvents();
        update();
        render();
        SDL_Delay(16);  // ~60 FPS
    }
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
    _ball->update();
    _playerPaddle->update();
    _machinePaddle->update();

    if (_machinePaddle->getRect().y + _machinePaddle->getRect().h / 2 < _ball->getRect().y) {
        _machinePaddle->moveDown();
    } else {
        _machinePaddle->moveUp();
    }

    if (SDL_HasIntersection(&_ball->getRect(), &_playerPaddle->getRect()) ||
        SDL_HasIntersection(&_ball->getRect(), &_machinePaddle->getRect())) {
        _ball->reverseX();
    }
    if (_ball->getRect().x < 0 || _ball->getRect().x > 800) {
        _ball->reset();
    }
}

void GameApp::render() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); 
    SDL_RenderClear(_renderer);

    _playerPaddle->render();
    _machinePaddle->render();
    _ball->render();

    SDL_RenderPresent(_renderer);
}
