#include "Scene.hpp"

using namespace App::Algs;

namespace App::Game {
    void Scene::checkBorders(const unsigned int x, const unsigned int y) {
        if (x >= this->width) {
            throw std::invalid_argument("x >= width"); 
        }
        if (y >= this->height) {
            throw std::invalid_argument("y >= height");
        }
    }
    
    Scene::Scene(const unsigned int width, const unsigned int height): width(width), height(height) {
        Block pathBlock = Block(BlockType::PATH);
        for (unsigned int i = 0; i < this->length(); i++) {
            this->scene.push_back(pathBlock);
        }
    }
    
    Scene::Scene(const unsigned int width, std::vector<int> walls): width(width) {
        this->height = walls.size() / this->width;
        Block pathBlock = Block(BlockType::PATH);
        Block wallBlock = Block(BlockType::WALL);
        for (unsigned int i = 0; i < this->length(); i++) {
            this->scene.push_back(walls[i] ? wallBlock : pathBlock);
        }
    }    
    
    unsigned int Scene::getWidth() {
        return this->width;
    }
    
    unsigned int Scene::getHeight() {
        return this->height;
    }
    
    Block Scene::getBlock(const unsigned int x, const unsigned int y) {
        const size_t n = this->calcIndex(x, y);
        return this->scene[n];
    }
    
    void Scene::setBlock(Block block, const unsigned int x, const unsigned int y) {
        const size_t n = this->calcIndex(x, y);
        this->scene[n] = block;
    }
    
    size_t Scene::length() {
        return this->width * this->height;
    }
    
    size_t Scene::calcIndex(const unsigned int x, const unsigned int y) {
        this->checkBorders(x, y);
        return y * this->width + x;
    }
    
    Point Scene::calcXY(const size_t index) {
        const unsigned int x = index % this->width;
        const unsigned int y = index / this->width;
        return Point(x, y);
    }
    
    Block Scene::getBlockByIndex(const size_t index) {
        return this->scene[index];
    }
    
    void Scene::putScene(Scene scene, const unsigned int x, const unsigned int y) {
        const size_t length = scene.length();
        for (size_t i = 0; i < length; i++) {
            Point point = scene.calcXY(i);
            Block block = scene.getBlockByIndex(i);
            this->setBlock(block, point.getX() + x, point.getY() + y);
        }
    }
}
