#pragma once
#include <cstddef>
#include <iostream>
#include <ncurses.h>
#include <any>
#include "../IScreen.hpp"
#include "../../Game/Scene.hpp"
#include "../../Game/Block.hpp"

namespace App::IO::Terminal {
    enum class ScreenColor 
    {
        WHITE_BLACK = 1,
        YELLOW_BLACK,
        BLACK_RED,
        GREEN_BLACK,
        RED_BLACK,
        BLUE_BLACK,
        EOE
    };
    
    class Screen : public App::IO::IScreen 
    {
        public:
            Screen();
            ~Screen();
            void echo(int x, int y, const char *text, ScreenColor color = ScreenColor::WHITE_BLACK);
            void drawScene(App::Game::Scene &scene);
            void flip();
            unsigned int getWidth();
            unsigned int getHeight();
    };
}
