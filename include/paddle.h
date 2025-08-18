#pragma once

#include "sceneitem.h"
#include "renderer.h"

namespace game {
    using game::SceneItem;
    using game::Renderer;

    class Paddle : public SceneItem {
        public:
            Paddle();
            virtual ~Paddle();

            virtual void update(long delta);
            virtual void render(Renderer* renderer);
            void moveUp();
            void moveDown();

        private:
            int _speed;
    };
}