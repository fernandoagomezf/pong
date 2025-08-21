
#pragma once 

#include "event.h"
#include "paddledirection.h"

namespace game {
    class PaddleMovedEvent : public Event {
        public:
            PaddleMovedEvent(const PaddleDirection& direction);
            PaddleMovedEvent(const PaddleMovedEvent& other);
            virtual ~PaddleMovedEvent();

            PaddleDirection direction() const;

            PaddleMovedEvent& operator= (const PaddleMovedEvent& other);

        private:
            PaddleDirection _direction;
    };
} 