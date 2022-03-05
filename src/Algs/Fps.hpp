#pragma once
#include <cstddef>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <ratio>
#include "../globals.h"

namespace App::Algs {
    class Fps
    {
        private:
            unsigned int interval;
            unsigned long int last = 0;
        
        public:
            Fps(unsigned int interval = 0);
            void setInterval(unsigned int interval);
            bool isTime();
    };
}
