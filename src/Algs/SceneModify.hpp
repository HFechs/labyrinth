#pragma once
#include <cstddef>
#include <functional>
#include <stdexcept>
#include "../Game/Scene.hpp"

namespace App::Algs {
    class SceneModify {
        private:
            static void modify(
                App::Game::Scene &scene, 
                std::function<unsigned int(const unsigned int, const unsigned int, const unsigned int, const unsigned int)> calcX, 
                std::function<unsigned int(const unsigned int, const unsigned int, const unsigned int, const unsigned int)> calcY
            );
        
        public:
            static void leftRotate(App::Game::Scene &scene);
            static void rightRotate(App::Game::Scene &scene);
            static void verticalFlip(App::Game::Scene &scene);
            static void horizontalFlip(App::Game::Scene &scene);
    };
}
