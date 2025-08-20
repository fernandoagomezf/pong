
#pragma once

#include "eventbus.h"

namespace game {
    class InputHandler {
        public:
            InputHandler(game::EventBus* bus);
            ~InputHandler();

            void dispatch();

        private:
            game::EventBus* _bus;
    };
}
