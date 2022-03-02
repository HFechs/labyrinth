#pragma once

namespace App::IO {
    class IScreen
    {
        public:
            virtual void flip() = 0;
    };
}
