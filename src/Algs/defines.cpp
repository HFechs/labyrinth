#include "defines.hpp"

namespace App::Algs {
    signed int (&DirectionV::getVX())[4] {
        static signed int v[4];
        v[(size_t) Direction::RIGHT] = 1;
        v[(size_t) Direction::TOP] = 0;
        v[(size_t) Direction::LEFT] = -1;
        v[(size_t) Direction::BOTTOM] = 0;
        return v;
    }
    
    signed int (&DirectionV::getVY())[4] {
        static signed int v[4];
        v[(size_t) Direction::RIGHT] = 0;
        v[(size_t) Direction::TOP] = -1;
        v[(size_t) Direction::LEFT] = 0;
        v[(size_t) Direction::BOTTOM] = 1;
        return v;
    }        
}
