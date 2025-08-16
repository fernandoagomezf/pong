
#pragma once

#include "common.h"
#include "scene.h"
#include "paddle.h"
#include "ball.h"

namespace game {
    using game::Ball;
    using game::Paddle;

    class CourtScene : public Scene {
        public:
            CourtScene();
            CourtScene(SDL_Window* window, SDL_Renderer* renderer);
            virtual ~CourtScene();

            virtual void update(long delta);

        protected:
            virtual void loadItems();
            virtual void unloadItems();

        private:
            Ball* _ball;
            Paddle* _playerPaddle;
            Paddle* _machinePaddle;
    };
}
