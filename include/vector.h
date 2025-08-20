
#pragma once 

namespace game {
    class Vector {
        public:
            Vector();
            Vector(float x, float y);
            Vector(const Vector& other);
            ~Vector();

            float x() const;
            float y() const;

            Vector normalize() const;
            Vector scale(float scalar) const;
            Vector add(const Vector& other) const;
            Vector substract(const Vector& other) const;
            float length() const;

            Vector& operator= (const Vector& other);
            bool operator== (const Vector& other) const;
            bool operator!= (const Vector& other) const;

        private:
            float _x;
            float _y;
    };
}