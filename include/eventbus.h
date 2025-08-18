
#pragma once

#include "common.h"
#include "event.h"

namespace game {
    using std::function;
    using std::vector;
    using std::unordered_map;
    using game::Event;
    
    class EventBus {
        public:
            EventBus();
            ~EventBus();

            void subscribe(Event event, function<void()> callback);
            void clear(Event event);
            void publish(Event event);

        private:
            unordered_map<Event, vector<function<void()>>> _subscribers;
    };
}