#include "Events.hpp"

using namespace App::IO;

namespace App::IO::Terminal {
    std::map<int, Key> Events::getKeyMap() {
        std::map<int, Key> map = {
            {KEY_UP, Key::K_UP}, 
            {KEY_DOWN, Key::K_DOWN}, 
            {KEY_LEFT, Key::K_LEFT},
            {KEY_RIGHT, Key::K_RIGHT}
        };
        return map;
    }

    Event Events::get(int &value) {
        int key = getch();
        if (key) {
            std::map<int, Key> keyMap = this->getKeyMap();
            auto search = keyMap.find(key);
            if (search != keyMap.end()) {
                value = (int) search->second;
            } else {
                value = key;
            }
            return Event::KEY_PRESSED;
        } else {
            return Event::NONE;
        }
    }
}
