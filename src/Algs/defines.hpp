#pragma once
#include <cstddef>
#include <vector>

namespace App::Algs {
    enum class Direction {
        RIGHT,
        TOP,
        LEFT,
        BOTTOM
    };
    
    typedef std::vector<unsigned int> Path;
    
    class DirectionV {
        private: 
            DirectionV();
        
        public:
            static signed int (&getVX())[4];
            static signed int (&getVY())[4];
    };
}
