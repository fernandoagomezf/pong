#pragma once

#include "point.h"
#include "dimension.h"
#include "updatable.h"
#include "renderable.h"

namespace game {
    class Point;
    class Dimension;
    class Scene;
    class Updatable;
    class Renderable;

    class SceneItem : public Updatable, public Renderable {
        public:
            virtual ~SceneItem();

            Point point() const;
            Dimension dimension() const;
            
            void moveTo(const Point& point);
            void resize(const Dimension& dimension);
            virtual void update(long delta);
            virtual void render(Scene* scene);         

        protected:
            SceneItem();

            virtual bool isValidPoint(const Point& value);
            virtual bool isValidDimension(const Dimension& value);

        private:
            Point _point;
            Dimension _dimension;
    };
}

