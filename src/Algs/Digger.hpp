#pragma once
#include <cstddef>
#include <vector>
#include <map>
#include <algorithm>
#include "../Game/Scene.hpp"
#include "Explorer.hpp"
#include "defines.hpp"

namespace App::Algs {
    enum class DiggerReturn {
        FOUND,
        DIGGED,
        NOT_FOUND_TRAP,
        EOE
    };
    
    class Digger
    {
        private:
            Digger();
            
        public:
            static DiggerReturn dig(App::Game::Scene &scene, Point &position, Point end, Path &explored);
    };
}
