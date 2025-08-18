
#pragma once

#include "common.h"
#include "event.h"
#include "eventbus.h"

namespace game {
    using game::EventBus;

    class InputHandler {
        public:
            InputHandler(EventBus* bus);
            ~InputHandler();

            void dispatch();

        private:
            EventBus* _bus;
    };
}
