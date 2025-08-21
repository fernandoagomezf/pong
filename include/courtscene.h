
#pragma once

#include "scene.h"
#include "paddle.h"
#include "ball.h"
#include "renderer.h"
#include "eventbus.h"
#include "boundarycollisionevent.h"
#include "collisionevent.h"
#include "paddlemovedevent.h"

namespace game {
    class CourtScene : public Scene {
        public:
            CourtScene(EventBus* bus);
            virtual ~CourtScene();

            virtual void load() override;
            virtual void unload() override;
            virtual void update(float delta) override;

        private:            
            void onPaddleMoved(const PaddleMovedEvent* event);
            void onBallPaddleCollided(const CollisionEvent* event);
            void onBallBoundaryCollided(const BoundaryCollisionEvent* event);
            
            Ball* _ball;
            Paddle* _playerPaddle;
            Paddle* _machinePaddle;
    };
}
