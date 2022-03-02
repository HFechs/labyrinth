#pragma once
#include <cstddef>

namespace App::Game {
    enum class BlockType {
        PATH,
        START,
        END,
        WALL,
        PLAYER,
        ENEMY,
        DEBUG1,
        DEBUG2,
        DEBUG3,
        EOE
    };
    
    class Block
    {
        private:
            BlockType type;
        public:
            Block(BlockType type);
            BlockType getType();
    };
}
