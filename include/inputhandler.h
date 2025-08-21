
#pragma once

#include "eventbus.h"

namespace game {
    class InputHandler {
        public:
            InputHandler(EventBus* bus);
            ~InputHandler();

            void dispatch();

        private:
            EventBus* _bus;
    };
}
