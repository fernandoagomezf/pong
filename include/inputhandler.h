
#pragma once

#include "common.h"
#include "event.h"
#include "eventbus.h"

namespace game {
    class EventBus;

    class InputHandler {
        public:
            InputHandler(EventBus* bus);
            ~InputHandler();

            void handle(const SDL_Event& event);

        private:
            EventBus* _bus;
    };
}
