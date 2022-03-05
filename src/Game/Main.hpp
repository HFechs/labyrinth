#pragma once
#include <cstddef>
#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Scene.hpp"
#include "Block.hpp"
#include "Enemy.hpp"
#include "../Algs/Labyrinth.hpp"
#include "../Algs/Tunneler.hpp"
#include "../IO/IEvents.hpp"
#include "../IO/IScreen.hpp"

namespace App::Game {
    class Main
    {
        private:
            App::IO::IScreen &screen;
            App::IO::IEvents &events;
            void generateScene(App::Game::Scene &scene, unsigned int width, unsigned int height);
        
        public:
            Main(App::IO::IScreen &screen, App::IO::IEvents &events);
            ~Main();
            void loop();
    };
}
