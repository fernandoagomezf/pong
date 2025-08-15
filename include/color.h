#pragma once 

namespace game {
    class Color {
        public:
            Color(int red, int green, int blue);
            Color(int red, int green, int blue, int alpha);
            Color(const Color& other);
            ~Color();

            int r() const;
            int g() const;
            int b() const;
            int a() const;

            Color& operator= (const Color& other);
            bool operator == (const Color& other);
            bool operator != (const Color& other);

            static Color white();
            static Color black();
            static Color red();
            static Color green();
            static Color blue();
            static Color yellow();
            static Color cyan();
            static Color magenta();
            static Color gray();
            static Color darkRed();
            static Color forestGreen();
            static Color navyBlue();
            static Color gold();
            static Color orange();
            static Color pink();
            static Color purple();

        private:
            Color();

            static bool isValid(int val);

            int _r;
            int _g;
            int _b;
            int _a;

            static const int _minVal = 0;
            static const int _maxVal = 255;
    };
}
