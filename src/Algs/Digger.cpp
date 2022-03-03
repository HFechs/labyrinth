#include "Digger.hpp"

using namespace App::Game;

namespace App::Algs {
    DiggerReturn Digger::dig(App::Game::Scene &scene, Point &position, Point end, Path &explored) {
        Path path;
        const ExplorerReturn eret = Explorer::explore(scene, position, end, explored, path);
        explored.insert(explored.end(), path.begin(), path.end());
        
        if (eret == ExplorerReturn::FOUND) {
            return DiggerReturn::FOUND; 
        }
        
        auto &VX = DirectionV::getVX();
        auto &VY = DirectionV::getVY();
        size_t maxPathLength = 0;
        bool found = false;
        
        for (auto xy : path) {
            Scene scene2 = scene;
            Point point(xy);
            
            for (int i = 0; i < 4; i++) {
                const signed int x2 = (signed int) point.getX() + VX[i];
                const signed int y2 = (signed int) point.getY() + VY[i];
                
                if (x2 >= 0 && y2 >= 0 && x2 < (signed int) scene2.getWidth() && y2 < (signed int) scene2.getHeight() && !scene2.getBlock(x2, y2).isWalkable()) {
                    scene2.setBlock(Block(BlockType::PATH), x2, y2);
                    Path path2;
                    Explorer::explore(scene2, Point(x2, y2), end, explored, path2);
                    if (maxPathLength < path2.size() || !found) {
                        maxPathLength = path2.size();
                        position = Point(x2, y2);
                        found = true;
                    }
                }
            }
        }
        
        if (!found) {
            return DiggerReturn::NOT_FOUND_TRAP;
        }
        
        scene.setBlock(Block(BlockType::PATH), position.getX(), position.getY());
        return DiggerReturn::DIGGED;
    }
}
