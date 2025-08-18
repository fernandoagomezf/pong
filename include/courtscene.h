
#pragma once

#include "common.h"
#include "scene.h"
#include "paddle.h"
#include "ball.h"
#include "renderer.h"
#include "eventbus.h"

namespace game {
    using game::Ball;
    using game::Paddle;
    using game::EventBus;
    using game::Scene;
    using game::Renderer;

    class CourtScene : public Scene {
        public:
            CourtScene(Renderer* renderer, EventBus* bus);
            virtual ~CourtScene();

            virtual void load();
            virtual void unload();
            virtual void update(long delta);

        private:
            Ball* _ball;
            Paddle* _playerPaddle;
            Paddle* _machinePaddle;
    };
}
