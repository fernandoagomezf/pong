#pragma once

#include "sceneitem.h"

namespace game {
    class Scene;
    class SceneItem;

    class Paddle : public SceneItem {
        public:
            Paddle();
            virtual ~Paddle();

            virtual void update(long delta);
            virtual void render(Scene* scene);
            void moveUp();
            void moveDown();

        private:
            int _speed;
    };
}