#include "Fps.hpp"
#include <iostream>

namespace App::Algs {
    Fps::Fps(unsigned int interval): interval(interval) {}
    
    void Fps::setInterval(unsigned int interval) {
        this->interval = interval;    
    }
    
    bool Fps::isTime() {
        auto current = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        
        if (current - this->last >= (int) ((float) this->interval * GAME_SPEED)) {
            this->last = current;
            return true;
        }
        return false;
    }
}
