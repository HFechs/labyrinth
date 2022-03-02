#pragma once
#include <cstddef>
#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../IO/IEvents.hpp"
#include "../IO/IScreen.hpp"

namespace App::Game {
    class Main
    {
        private:
            App::IO::IScreen &screen;
            App::IO::IEvents &events;
        public:
            Main(App::IO::IScreen &screen, App::IO::IEvents &events);
            ~Main();
            void loop();
    };
}
