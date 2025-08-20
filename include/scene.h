#pragma once

#include <vector>
#include "sceneitem.h"
#include "eventbus.h"
#include "renderer.h"

namespace game {
    class Scene {
        public:
            Scene(game::EventBus* bus);
            virtual ~Scene();

            virtual void load() = 0;
            virtual void unload() = 0;

            virtual void update(float delta);
            virtual void render(game::Renderer* renderer);

        protected:
            void attach(game::SceneItem* item);
            void detach(game::SceneItem* item);

            game::EventBus* getBus() const;

        private:
            std::vector<game::SceneItem*> _items;
            game::EventBus* _bus;
    };
}