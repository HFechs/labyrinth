#include "Point.hpp"

namespace App::Algs {
    const size_t Point::BITS = 9;
    
    Point::Point(const unsigned int x, const unsigned int y): x(x), y(y) {}
    
    Point::Point(const unsigned int xy) {
        this->y = xy & ~(~0u << Point::BITS);
        this->x = xy >> Point::BITS;
    }
    
    unsigned int Point::getX() {
        return this->x;
    }
    
    unsigned int Point::getY() {
        return this->y;
    }
    
    unsigned int Point::getXY() {
        return (this->x << Point::BITS) | this->y;
    }
}
