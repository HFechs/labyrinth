#pragma once
#include <cstddef>
#include "../IPainter.hpp"
#include "Screen.hpp"

namespace App::IO::Terminal {
    struct BlockData {
        char ch;
        ScreenColor color;
    };
    
    class Painter : public App::IO::IPainter
    {
        public:
            std::any draw(App::Game::Block block);
    };
}
