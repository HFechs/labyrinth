#pragma once
#include <stdlib.h>
#include "Patterns.hpp"
#include "../Game/Scene.hpp"

namespace App::Algs {
    class Labyrinth
    {
        public:
            static void generate(App::Game::Scene &scene);
    };
}
