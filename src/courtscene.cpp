
#include "common.h"
#include "courtscene.h"

using game::Scene;
using game::CourtScene;

CourtScene::CourtScene(EventBus* bus)
    : Scene(bus) {
    _ball = new Ball();
    _playerPaddle = new Paddle();
    _machinePaddle = new Paddle();
}

CourtScene::CourtScene(EventBus* bus, SDL_Window* window, SDL_Renderer* renderer)
    : Scene(bus, window, renderer) {
    _ball = new Ball();
    _playerPaddle = new Paddle();
    _machinePaddle = new Paddle();
}

CourtScene::~CourtScene() {
    delete _ball;
    delete _playerPaddle;
    delete _machinePaddle;
}

void CourtScene::loadItems() {
    _ball->reset();
    attach(_ball);

    Point playerPaddlePt(50, 250);
    _playerPaddle->moveTo(playerPaddlePt);
    attach(_playerPaddle);

    Point machinePaddlePt(750, 250);
    _machinePaddle->moveTo(machinePaddlePt);
    attach(_machinePaddle);

    auto bus = getBus();
    bus->subscribe(Event::PADDLE_UP, [this]() {
        _playerPaddle->moveUp();
    });
    bus->subscribe(Event::PADDLE_DOWN, [this]() {
        _playerPaddle->moveDown();
    });
}

void CourtScene::unloadItems() {
    auto bus = getBus();
    bus->clear(Event::PADDLE_UP);
    bus->clear(Event::PADDLE_DOWN);
    detach(_ball);
    detach(_playerPaddle);
    detach(_machinePaddle);
}

void CourtScene::update(long delta) {
    Scene::update(delta);

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