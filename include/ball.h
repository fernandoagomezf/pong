#pragma once

struct SDL_Renderer;
struct SDL_Rect;

namespace game {
    class Ball {
        public:
            Ball(SDL_Renderer* renderer, int x, int y);
            ~Ball();

            void update();
            void render();
            void reset();
            void reverseX();
            SDL_Rect getRect() const;

        private:
            SDL_Renderer* _renderer;
            SDL_Rect _rect;
            int _velX;
            int _velY;
    };
}

