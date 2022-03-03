#include "Block.hpp"

namespace App::Game {
    Block::Block(BlockType type): type(type) {}
    
    BlockType Block::getType() {
        return this->type;
    }
    
    bool Block::isWalkable() {
        if (this->type == BlockType::WALL) {
            return false;
        }
        return true;
    }
}
