#pragma once

namespace game {
    class Dimension {
        public:
            Dimension(int width, int height);
            Dimension(const Dimension& other);
            ~Dimension();

            int width() const;
            int height() const;

            Dimension& operator= (const Dimension& other);
            bool operator== (const Dimension& other) const;
            bool operator!= (const Dimension& other) const;

        private:
            int _width;
            int _height;
    };
}