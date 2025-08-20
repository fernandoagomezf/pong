
#pragma once

#include "scene.h"
#include "paddle.h"
#include "ball.h"
#include "renderer.h"
#include "eventbus.h"

namespace game {
    class CourtScene : public game::Scene {
        public:
            CourtScene(EventBus* bus);
            virtual ~CourtScene();

            virtual void load();
            virtual void unload();
            virtual void update(float delta);

        private:
            game::Ball* _ball;
            game::Paddle* _playerPaddle;
            game::Paddle* _machinePaddle;
    };
}
