#pragma once
#include <cstddef>
#include <vector>
#include <algorithm>
#include "../Game/Scene.hpp"
#include "../Game/Block.hpp"
#include "Explorer.hpp"
#include "defines.hpp"

namespace App::Algs {
    class PathVisualizer
    {
        private:
            PathVisualizer();
            
        public:
            static void visualize(App::Game::Scene &scene, Path &path, App::Game::Block block);
            static void visualize(App::Game::Scene &scene, ExplorerRating &path, App::Game::Block block);
    };
}
