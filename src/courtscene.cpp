#include <stdexcept>
#include "courtscene.h"
#include "collisionevent.h"
#include "boundarycollisionevent.h"

using std::invalid_argument;
using std::runtime_error;
using game::Scene;
using game::CourtScene;
using game::EventBus;
using game::Paddle;
using game::Ball;
using game::Vector;
using game::CollisionEvent;
using game::BoundaryCollisionEvent;
using game::Rectangle;
using game::Edge;

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
    bus->subscribe<PaddleMovedEvent>([this](auto event) {
        onPaddleMoved(dynamic_cast<const PaddleMovedEvent*>(event));
    });
    bus->subscribe<CollisionEvent>([this](auto event) {
        onBallPaddleCollided(dynamic_cast<const CollisionEvent*>(event));
    });
    bus->subscribe<BoundaryCollisionEvent>([this](auto event) {
        onBallBoundaryCollided(dynamic_cast<const BoundaryCollisionEvent*>(event));
    });
}

void CourtScene::unload() {
    auto bus = getBus();
    bus->clear<PaddleMovedEvent>();
    detach(_ball);
    detach(_playerPaddle);
    detach(_machinePaddle);
}

void CourtScene::update(float delta) {
    // update scene items    
    Scene::update(delta);

    Rectangle courtRect(0.f, 0.f, 800.f, 600.f);
    Rectangle ballRect = _ball->rectangle();
    Rectangle machineRect = _machinePaddle->rectangle();
    EventBus* bus = getBus();

    // simple AI for the machine paddle
    if (machineRect.y() + machineRect.height() / 2 < ballRect.y()) {
        _machinePaddle->moveDown();
    } else {
        _machinePaddle->moveUp();
    }
   
    // check ball collisions with the court boundries    
    if (ballRect.x() <= courtRect.x()) {
        bus->publish(new BoundaryCollisionEvent(_ball, Edge::LEFT));
    } 
    if (ballRect.x() + ballRect.width() >= courtRect.x() + courtRect.width()){
        bus->publish(new BoundaryCollisionEvent(_ball, Edge::RIGHT));
    }
    if (ballRect.y() <= courtRect.y()) {
        bus->publish(new BoundaryCollisionEvent(_ball, Edge::TOP));
    } 
    if (ballRect.y() + ballRect.height() >= courtRect.y() + courtRect.height()){
        bus->publish(new BoundaryCollisionEvent(_ball, Edge::BOTTOM));
    }

    // check ball collisions with the paddles
    Rectangle playerPaddleRect = _playerPaddle->rectangle();
    if (ballRect.intersects(playerPaddleRect)) {
        bus->publish(new CollisionEvent(_ball, _playerPaddle));
    }
    Rectangle machinePaddleRect = _machinePaddle->rectangle();
    if (ballRect.intersects(machinePaddleRect)) {
        bus->publish(new CollisionEvent(_ball, _machinePaddle));
    }
}

void CourtScene::onPaddleMoved(const PaddleMovedEvent* event) {
    if (event == nullptr) {
        throw invalid_argument("Invalid paddle moved event.");
    }

    switch (event->direction()) {
        case PaddleDirection::UP:
            _playerPaddle->moveUp();
            break;
        case PaddleDirection::DOWN:
            _playerPaddle->moveDown();
            break;
        default:
            throw runtime_error("Invalid direction detected.");
    }
}

void CourtScene::onBallPaddleCollided(const CollisionEvent* event) {
    if (event == nullptr) {
        throw invalid_argument("Invalid collision event.");
    }

    _ball->bounce(true, false);
}

void CourtScene::onBallBoundaryCollided(const BoundaryCollisionEvent* event) {
    if (event == nullptr) {
        throw invalid_argument("Invalid boundry collision event.");
    }

    switch (event->edge()) {
        case Edge::TOP:
        case Edge::BOTTOM:
            _ball->bounce(false, true);
            break;
        case Edge::LEFT:
        case Edge::RIGHT:
            _ball->reset();
            break;
        default:
            throw runtime_error("Invalid edge collision detected.");
    }
}

