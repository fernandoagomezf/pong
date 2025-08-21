#pragma once

#include <string>

namespace game {    
    using std::string;
    
    class Event {
        public:
            virtual ~Event();

            string type() const;
        
        protected:
            Event();
            Event(const Event& other);

            Event& operator= (const Event& other);
    };
}
