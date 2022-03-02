#pragma once
#include <cstddef>

namespace App::Algs {
    class Point {
        private:
            unsigned int x;
            unsigned int y;
        
        public:
            static const size_t BITS;
            Point(const unsigned int x, const unsigned int y);
            Point(const unsigned int xy);
            unsigned int getX();
            unsigned int getY();
            unsigned int getXY();
    };
}
