#pragma once

#include <memory>
#include <string>
#include "vector.h"
#include "rectangle.h"
#include "color.h"

namespace game {
    using std::string;
    using std::unique_ptr;

    class Renderer {        
        public:
            Renderer();
            ~Renderer();

            void create(const string& title, const Vector& size);
            bool isCreated() const;
            void clear();
            void show();
            
            void draw(const Rectangle& rectangle, const Color& color);

        private:
            void ensureCreated() const;

            struct impl;
            std::unique_ptr<impl> _impl;
    };
}