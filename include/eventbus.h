
#pragma once

#include <functional>
#include <unordered_map>
#include <vector>
#include <typeinfo>
#include <memory>
#include "event.h"

namespace game {    
    using std::function;
    using std::string;

    class EventBus {
        public:
            typedef std::function<void(const Event*)> Callback;

            EventBus();
            ~EventBus();

            void subscribe(const std::string& eventType, Callback callback);
            void publish(game::Event* event);
            void clear(const std::string& eventType);
            
            template<typename TEvent>
            void subscribe(Callback callback) {
                subscribe(typeid(TEvent).raw_name(), callback);
            }

            template<typename TEvent>
            void clear() {
                clear(typeid(TEvent).raw_name());
            }

        private:
            std::unordered_map<std::string, std::vector<Callback>> _subscribers;
    };
}