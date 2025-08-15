#pragma once

namespace game {
    class Point{
        public:
            Point(int x, int y);
            Point(const Point& other);
            ~Point();

            int x() const;
            int y() const;

            Point& operator= (const Point& other);
            bool operator== (const Point& other) const;
            bool operator!= (const Point& other) const;

        private:
            int _x;
            int _y;
    };
}