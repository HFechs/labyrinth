#pragma once
#include <cstddef>
#include <iostream>
#include <map>
#include <ncurses.h>
#include "../IEvents.hpp"

namespace App::IO::Terminal {
    class Events : public App::IO::IEvents
    {
        private:
            std::map<int, Key> getKeyMap();
        public:
            virtual App::IO::Event get(int &value);
    };
}
