#pragma once
#include <cstddef>
#include <vector>
#include <map>
#include <algorithm>
#include "../Game/Scene.hpp"
#include "Digger.hpp"
#include "defines.hpp"

namespace App::Algs {
    enum class TunnelerReturn {
        FOUND,
        NOT_FOUND_TRAP,
        NOT_FOUND_LOOP,
        EOE
    };
    
    class Tunneler
    {
        private:
            Tunneler();
            
        public:
            static const unsigned int MAX_LOOP;
            static TunnelerReturn dig(App::Game::Scene &scene, Point start, Point end);
    };
}
