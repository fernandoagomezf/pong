
#pragma once 

namespace game {
    class Scene;

    class Renderable {
        public:
            virtual ~Renderable() = default;

            virtual void render(Scene* scene) = 0;
    };
}