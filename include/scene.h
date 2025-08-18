#pragma once

#include "common.h"
#include "updatable.h"
#include "sceneitem.h"
#include "eventbus.h"
#include "renderer.h"

namespace game {
    using std::vector;
    using game::EventBus;
    using game::Renderer;

    class Scene : public Updatable {
        public:
            Scene(Renderer* renderer, EventBus* bus);
            virtual ~Scene();

            virtual void load();
            virtual void unload();

            virtual void update(long delta);
            void render();

        protected:
            void attach(SceneItem* item);
            void detach(SceneItem* item);

            EventBus* getBus() const;
            Renderer* getRenderer() const;

        private:
            vector<SceneItem*> _items;
            EventBus* _bus;
            Renderer* _renderer;
    };
}