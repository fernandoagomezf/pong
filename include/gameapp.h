#pragma once

namespace game {
    class Scene;
    class InputHandler;
    class EventBus;

    class GameApp {
        public:
            GameApp();
            ~GameApp();

            void run();
            
        protected:
            void handleEvents();
            
        private:
            Scene* _scene;
            EventBus* _bus;
            InputHandler* _handler;
            bool _isRunning;
    };
}