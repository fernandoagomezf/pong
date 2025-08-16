#pragma once

#include "common.h"
#include "color.h"
#include "point.h"
#include "dimension.h"
#include "updatable.h"

struct SDL_Window;
struct SDL_Renderer;

namespace game {
    using std::vector;
    
    class SceneItem;

    class Scene : Updatable {
        public:
            Scene();
            Scene(SDL_Window* window, SDL_Renderer* renderer);
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

        private:
            SDL_Window* _window;
            SDL_Renderer* _renderer;
            Dimension _dimension;
            vector<SceneItem*> _items;
    };
}