#pragma once

struct SDL_Window;
struct SDL_Renderer;

namespace game {
    class Paddle;
    class Ball;

    class GameApp {
        public:
            GameApp();
            ~GameApp();

            void run();
            
        protected:
            void handleEvents();
            void update();
            void render();
            
        private:
            SDL_Window* _window;
            SDL_Renderer* _renderer;
            Ball* _ball;
            Paddle* _playerPaddle;
            Paddle* _machinePaddle;
            bool _isRunning;
    };
}