#pragma once

#include "common.h"
#include "dimension.h"
#include "point.h"
#include "color.h"

namespace game {
    using std::unique_ptr;
    using std::string;
    using game::Color;
    using game::Dimension;
    using game::Point;

    class Renderer {        
        public:
            Renderer();
            ~Renderer();

            void create(const string& title, const Dimension& dimension);
            bool isCreated() const;
            void clear();
            void show();
            
            void draw(const Point& pt, const Dimension& dim, const Color& color);

        private:
            void ensureCreated() const;

            struct Impl;
            unique_ptr<Impl> _impl;
    };
}