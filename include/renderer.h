#pragma once

#include <memory>
#include <string>
#include "vector.h"
#include "rectangle.h"
#include "color.h"

namespace game {
    class Renderer {        
        public:
            Renderer();
            ~Renderer();

            void create(const std::string& title, const Vector& size);
            bool isCreated() const;
            void clear();
            void show();
            
            void draw(const game::Rectangle& rectangle, const Color& color);

        private:
            void ensureCreated() const;

            struct Impl;
            std::unique_ptr<Impl> _impl;
    };
}