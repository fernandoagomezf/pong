#pragma once

#include "sceneitem.h"
#include "renderer.h"
#include "vector.h"

namespace game {
    class Ball : public game::SceneItem {
        public:
            Ball();
            virtual ~Ball();

            virtual void update(float delta);
            virtual void render(game::Renderer* renderer);

            void reset();
            void reverseX();         
            void reverseY();   

        private:
            float _speed;
            game::Vector _direction;
    };
}

