#pragma once
#include <cstddef>
#include "Patterns.hpp"
#include "../Game/Scene.hpp"

namespace App::Algs {
    class Labyrinth
    {
        private:
            Labyrinth();
        
        public:
            static void generate(App::Game::Scene &scene);
    };
}
