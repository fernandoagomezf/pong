#pragma once

#include "point.h"
#include "dimension.h"
#include "updatable.h"
#include "renderable.h"
#include "renderer.h"

namespace game {
    using game::Point;
    using game::Dimension;
    using game::Renderer;
    using game::Renderable;

    class SceneItem : public Updatable, public Renderable {
        public:
            virtual ~SceneItem();

            Point point() const;
            Dimension dimension() const;
            
            void moveTo(const Point& point);
            void resize(const Dimension& dimension);
            virtual void update(long delta);
            virtual void render(Renderer* renderer);         

        protected:
            SceneItem();

            virtual bool isValidPoint(const Point& value);
            virtual bool isValidDimension(const Dimension& value);

        private:
            Point _point;
            Dimension _dimension;
    };
}

