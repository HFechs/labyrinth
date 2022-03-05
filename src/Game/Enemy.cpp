#include "Enemy.hpp"
#include <iostream>

using namespace App::Algs;

namespace App::Game {
    void Enemy::move(Point target) {
        //std::cerr << "A " << this->position.getX() << "|" << this->position.getY() << std::endl;
        this->scene.setBlock(this->block, this->position.getX(), this->position.getY());
        this->block = scene.getBlock(target.getX(), target.getY());
        scene.setBlock(Block(BlockType::ENEMY), target.getX(), target.getY());
        this->position = target;
        //std::cerr << "B " << this->position.getX() << "|" << this->position.getY() << std::endl;
    }
   
    Enemy::Enemy(Scene &scene, Point start, Point end): scene(scene), start(start), end(end) {
        this->fps.setInterval(500);
        this->position = start;
        this->block = scene.getBlock(this->position.getX(), this->position.getY());
        this->move(this->position);
    }
    
    bool Enemy::step() {
        if (!this->fps.isTime()) {
            return false;
        }
        
        Path path;
        Explorer::explore(scene, this->start, this->end, this->position, this->direction, this->rating, 1, path);
        if (path.size() > 1) {
            for (auto xy : path) {
                if(xy != this->position.getXY()) {
                    this->move(Point(xy));
                }
            }
        }
        
        return true;
    }
}
