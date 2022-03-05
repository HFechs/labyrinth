#pragma once
#include <cstddef>
#include <vector>
#include <stdexcept>
#include <chrono>
#include "Block.hpp"
#include "../Algs/defines.hpp"
#include "../Algs/Point.hpp"
#include "../Algs/Fps.hpp"
#include "../Algs/Explorer.hpp"
#include "../Algs/defines.hpp"

namespace App::Game {
    class Enemy
    {
        private:
            Scene &scene;
            App::Algs::Point start;
            App::Algs::Point position;
            App::Algs::Point end;
            Block block;
            App::Algs::Fps fps;
            App::Algs::Direction direction = App::Algs::Direction::RIGHT;
            App::Algs::ExplorerRating rating;
            void move(App::Algs::Point target);
        
        public:
            Enemy(Scene &scene, App::Algs::Point start, App::Algs::Point end);
            bool step();
    };
}
