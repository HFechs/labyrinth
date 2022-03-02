#pragma once
#include <cstddef>
#include <vector>
#include "../Game/Scene.hpp"
#include "../Algs/SceneModify.hpp"

namespace App::Algs {
    class Patterns
    {
        private:
            std::vector<App::Game::Scene> patterns;
            
        public:
            static const size_t SIZE;
            Patterns();
            size_t count();
            App::Game::Scene get(size_t n);
    };
}
