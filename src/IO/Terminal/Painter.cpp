#include "Painter.hpp"

using namespace App::Game;

namespace App::IO::Terminal {
    std::any Painter::draw(Block block) {
        char mapCh[(size_t) BlockType::EOE];
        mapCh[(size_t) BlockType::PATH] = ' ';
        mapCh[(size_t) BlockType::START] = '+';
        mapCh[(size_t) BlockType::END] = 'x';
        mapCh[(size_t) BlockType::WALL] = '#';
        mapCh[(size_t) BlockType::PLAYER] = '@';
        mapCh[(size_t) BlockType::ENEMY] = '$';
        mapCh[(size_t) BlockType::DEBUG1] = '1';
        mapCh[(size_t) BlockType::DEBUG2] = '2';
        mapCh[(size_t) BlockType::DEBUG3] = '3';
        
        ScreenColor mapColor[(size_t) BlockType::EOE];
        mapColor[(size_t) BlockType::PATH] = ScreenColor::WHITE_BLACK;
        mapColor[(size_t) BlockType::START] = ScreenColor::YELLOW_BLACK;
        mapColor[(size_t) BlockType::END] = ScreenColor::YELLOW_BLACK;
        mapColor[(size_t) BlockType::WALL] = ScreenColor::BLACK_RED;
        mapColor[(size_t) BlockType::PLAYER] = ScreenColor::GREEN_BLACK;
        mapColor[(size_t) BlockType::ENEMY] = ScreenColor::GREEN_BLACK;
        mapColor[(size_t) BlockType::DEBUG1] = ScreenColor::BLUE_BLACK;
        mapColor[(size_t) BlockType::DEBUG2] = ScreenColor::GREEN_BLACK;
        mapColor[(size_t) BlockType::DEBUG3] = ScreenColor::RED_BLACK;

       
        BlockData blockData;
        blockData.ch = mapCh[(size_t) block.getType()];
        blockData.color = mapColor[(size_t) block.getType()];
        
        std::any out = blockData;
        return out;
    }
}
