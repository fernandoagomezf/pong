
#pragma once

#include "point.h"
#include "dimension.h"

namespace game {
    using game::Point;
    using game::Dimension;

    class Rectangle {
        public:
            Rectangle(int x, int y, int width, int height);
            Rectangle(const Point& point, const Dimension& dimension);
            Rectangle(const Rectangle& other);
            ~Rectangle();

            int x() const;
            int y() const;
            int width() const;
            int height() const;

            Point getOriginPoint() const;
            Point getEndPoint() const;
            Dimension getDimension() const;

            bool intersects(const Rectangle& other) const;

            Rectangle& operator= (const Rectangle& other);
            bool operator== (const Rectangle& other) const;
            bool operator!= (const Rectangle& other) const;

        private:
            int _x;
            int _y;
            int _width;
            int _height;
    };
}