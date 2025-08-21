#pragma once

#include "scene.h"
#include "inputhandler.h"
#include "eventbus.h"
#include "renderer.h"

namespace game {
    class GameApp {
        public:
            GameApp();
            ~GameApp();

            void run();
            void quit();            
            
        private:
            Scene* _scene;
            EventBus* _bus;
            InputHandler* _handler;
            Renderer* _renderer;
            bool _isRunning;
    };
}