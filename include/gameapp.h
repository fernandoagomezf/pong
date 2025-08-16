#pragma once

namespace game {
    class Paddle;
    class Ball;
    class Scene;

    class GameApp {
        public:
            GameApp();
            ~GameApp();

            void run();
            
        protected:
            void handleEvents();
            
        private:
            Scene* _scene;
            Ball* _ball;
            Paddle* _playerPaddle;
            Paddle* _machinePaddle;
            bool _isRunning;
    };
}