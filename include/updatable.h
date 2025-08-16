
#pragma once

namespace game {
    class Updatable {
        public:
            virtual ~Updatable() = default;

            virtual void update(long delta) = 0;
    };
}