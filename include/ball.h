#pragma once

#include "sceneitem.h"
#include "renderer.h"
#include "vector.h"

namespace game {
    class Ball : public SceneItem {
        public:
            Ball();
            virtual ~Ball();

            virtual void update(float delta) override;
            virtual void render(Renderer* renderer) override;

            void reset();
            void bounce(bool horizontal, bool vertical);

            float _speed;
            Vector _direction;
    };
}

