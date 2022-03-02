#pragma once
#include <cstddef>
#include <vector>
#include <stdexcept>
#include "Block.hpp"
#include "../Algs/Point.hpp"

namespace App::Game {
    class Scene
    {
        private:
            std::vector<Block> scene;
            unsigned int width = 0;
            unsigned int height = 0;
            void checkBorders(const unsigned int x, const unsigned int y);
        public:
            Scene(const unsigned int width, const unsigned int height);
            Scene(const unsigned int width, std::vector<int> walls);
            unsigned int getWidth();
            unsigned int getHeight();
            Block getBlock(const unsigned int x, const unsigned int y);
            void setBlock(Block block, const unsigned int x, const unsigned int y);
            size_t length();
            size_t calcIndex(const unsigned int x, const unsigned int y);
            App::Algs::Point calcXY(const size_t index);
            Block getBlockByIndex(const size_t index);
            void putScene(Scene scene, const unsigned int x, const unsigned int y);
    };
}
