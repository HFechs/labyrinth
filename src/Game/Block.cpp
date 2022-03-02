#include "Block.hpp"

namespace App::Game {
    Block::Block(BlockType type): type(type) {}
    
    BlockType Block::getType() {
        return this->type;
    }
}
