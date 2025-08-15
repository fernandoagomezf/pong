#pragma once

#include "color.h"
#include "point.h"
#include "dimension.h"

struct SDL_Window;
struct SDL_Renderer;

namespace game {
    class Color;
    class Point;
    class Dimension;

    class Scene {
        public:
            Scene();
            Scene(SDL_Window* window, SDL_Renderer* renderer);
            virtual ~Scene();

            void load();
            void unload();
            void drawZone(const Point& pt, const Dimension& dim, const Color& color);
            void clear();
            void show();

        private:
            SDL_Window* _window;
            SDL_Renderer* _renderer;
            Dimension _dimension;
    };
}