#pragma once

#include "common.h"
#include "color.h"
#include "point.h"
#include "dimension.h"
#include "updatable.h"
#include "sceneitem.h"
#include "inputhandler.h"

namespace game {
    using std::vector;
    using game::EventBus;

    class Scene : public Updatable {
        public:
            Scene(EventBus* bus);
            Scene(EventBus* bus, SDL_Window* window, SDL_Renderer* renderer);
            virtual ~Scene();

            void load();
            void unload();
            void draw(const Point& pt, const Dimension& dim, const Color& color);

            virtual void update(long delta);
            void render();

        protected:
            void attach(SceneItem* item);
            void detach(SceneItem* item);
            virtual void loadItems() = 0;
            virtual void unloadItems() = 0;

            EventBus* getBus() const;

        private:
            SDL_Window* _window;
            SDL_Renderer* _renderer;
            Dimension _dimension;
            vector<SceneItem*> _items;
            EventBus* _bus;
    };
}