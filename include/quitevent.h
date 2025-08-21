#pragma once

#include "event.h"

namespace game {
    class QuitEvent : public Event {
        public:
            QuitEvent();
            QuitEvent(const QuitEvent& other);
            virtual ~QuitEvent();

            QuitEvent& operator= (const QuitEvent& other);
    };
}