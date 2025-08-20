#pragma once

#include "sceneitem.h"
#include "renderer.h"

namespace game {
    class Wall : public game::SceneItem {
        public:
            Wall();
            virtual ~Wall();

            virtual void update(float delta);
            virtual void render(Renderer* renderer);
    };
}