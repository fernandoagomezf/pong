#pragma once

#include "sceneitem.h"
#include "renderer.h"

namespace game {
    class Paddle : public game::SceneItem {
        public:
            Paddle();
            virtual ~Paddle();

            virtual void update(float delta);
            virtual void render(game::Renderer* renderer);
            void moveUp();
            void moveDown();

        private:
            int _speed;
    };
}