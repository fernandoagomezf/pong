
#include "courtscene.h"

using game::Scene;
using game::CourtScene;
using game::EventBus;
using game::Paddle;
using game::Ball;
using game::Vector;

CourtScene::CourtScene(EventBus* bus)
    : Scene(bus) {
    _ball = new Ball();
    _playerPaddle = new Paddle();
    _machinePaddle = new Paddle();
}

CourtScene::~CourtScene() {
    delete _ball;
    delete _playerPaddle;
    delete _machinePaddle;
}

void CourtScene::load() {
    _ball->reset();
    attach(_ball);

    Vector playerPaddlePt(50.f, 250.f);
    _playerPaddle->moveTo(playerPaddlePt);
    attach(_playerPaddle);

    Vector machinePaddlePt(750, 250);
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

void CourtScene::unload() {
    auto bus = getBus();
    bus->clear(Event::PADDLE_UP);
    bus->clear(Event::PADDLE_DOWN);
    detach(_ball);
    detach(_playerPaddle);
    detach(_machinePaddle);
}

void CourtScene::update(float delta) {
    Scene::update(delta);

    auto ballRect = _ball->rectangle();
    auto machineRect = _machinePaddle->rectangle();
    auto playerRect = _playerPaddle->rectangle();
    
    if (machineRect.y() + machineRect.height() / 2 < ballRect.y()) {
        _machinePaddle->moveDown();
    } else {
        _machinePaddle->moveUp();
    }

    if (ballRect.intersects(playerRect) || ballRect.intersects(machineRect)) {
        _ball->reverseX();
    }
    if (ballRect.x() < 0.0f || ballRect.x() > 800.0f) {
        _ball->reset();
    }
}