
#pragma once 

#include "renderer.h"

namespace game {
    using game::Renderer;

    class Renderable {
        public:
            virtual ~Renderable() = default;

            virtual void render(Renderer* renderer) = 0;
    };
}