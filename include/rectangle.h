
#pragma once

#include "vector.h"

namespace game {
    class Rectangle {
        public:
            Rectangle(float x, float y, float width, float height);
            Rectangle(const Vector& position, const Vector& size);
            Rectangle(const Rectangle& other);
            ~Rectangle();

            float x() const;
            float y() const;
            float width() const;
            float height() const;

            Vector originPosition() const;
            Vector endPosition() const;
            Vector size() const;

            bool intersects(const Rectangle& other) const;

            Rectangle& operator= (const Rectangle& other);
            bool operator== (const Rectangle& other) const;
            bool operator!= (const Rectangle& other) const;

        private:
            float _x;
            float _y;
            float _width;
            float _height;
    };
}