#pragma once

#include <vector>
#include "sceneitem.h"
#include "eventbus.h"
#include "renderer.h"

namespace game {
    using std::vector;

    class Scene {
        public:
            Scene(EventBus* bus);
            virtual ~Scene();

            virtual void load() = 0;
            virtual void unload() = 0;

            virtual void update(float delta);
            virtual void render(Renderer* renderer);

        protected:
            void attach(SceneItem* item);
            void detach(SceneItem* item);

            EventBus* getBus() const;

        private:
            vector<SceneItem*> _items;
            EventBus* _bus;
    };
}