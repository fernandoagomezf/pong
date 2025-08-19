#pragma once

#include "point.h"
#include "dimension.h"
#include "updatable.h"
#include "renderable.h"
#include "renderer.h"
#include "rectangle.h"

namespace game {
    using game::Point;
    using game::Dimension;
    using game::Renderer;
    using game::Renderable;
    using game::Rectangle;

    class SceneItem : public Updatable, public Renderable {
        public:
            virtual ~SceneItem();

            Point point() const;
            Dimension dimension() const;
            Rectangle rectangle() const;
            
            void moveTo(const Point& point);
            void redim(const Dimension& dimension);
            virtual void update(long delta);
            virtual void render(Renderer* renderer);         

        protected:
            SceneItem();

        private:
            Rectangle _rectangle;
    };
}

