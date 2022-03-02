#pragma once
#include <cstddef>
#include <any>
#include "../Game/Block.hpp"

namespace App::IO {
    class IPainter
    {
        public:
            virtual std::any draw(App::Game::Block block) = 0;
    };
}
