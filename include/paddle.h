#pragma once

struct SDL_Rect;
struct SDL_Renderer;

namespace game {
    class Paddle {
        public:
            Paddle(SDL_Renderer* renderer, int x, int y);
            ~Paddle();

            void update();
            void render();
            void moveUp();
            void moveDown();
            SDL_Rect getRect() const;

        private:
            SDL_Renderer* _renderer;
            SDL_Rect _rect;
            int _speed;
    };
}