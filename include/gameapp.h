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
            game::Scene* _scene;
            game::EventBus* _bus;
            game::InputHandler* _handler;
            game::Renderer* _renderer;
            bool _isRunning;
    };
}