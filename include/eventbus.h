
#pragma once

#include "event.h"
#include <functional>
#include <unordered_map>
#include <vector>

namespace game {    
    class EventBus {
        public:
            EventBus();
            ~EventBus();

            void subscribe(game::Event event, std::function<void()> callback);
            void clear(game::Event event);
            void publish(game::Event event);

        private:
            std::unordered_map<game::Event, std::vector<std::function<void()>>> _subscribers;
    };
}