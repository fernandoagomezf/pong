#pragma once

#include "sceneitem.h"

namespace game {    
    class Scene;
    class SceneItem;

    class Ball : public SceneItem {
        public:
            Ball();
            virtual ~Ball();

            virtual void update(long delta);
            virtual void render(Scene* scene);

            void reset();
            void reverseX();            

        private:
            int _velX;
            int _velY;
    };
}

