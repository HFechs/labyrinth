#pragma once

namespace App::IO {
    enum class Event {
        NONE,
        KEY_PRESSED,
        EOE
    };

    enum class Key {
        K_UP,
        K_DOWN,
        K_LEFT,
        K_RIGHT,
        EOE
    };

    class IEvents
    {
        public:
            virtual Event get(int &value) = 0;
    };
}
