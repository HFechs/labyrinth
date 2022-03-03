#include "PathVisualizer.hpp"

using namespace App::Game;

namespace App::Algs {
    void PathVisualizer::visualize(App::Game::Scene &scene, Path &path, Block block) {
        for (auto xy : path) {
            Point point = Point(xy);
            scene.setBlock(block, point.getX(), point.getY());
        }
    }
    
    void PathVisualizer::visualize(App::Game::Scene &scene, ExplorerRating &path, Block block) {
        for (auto &it : path) {
            Point point = Point(it.first);
            scene.setBlock(block, point.getX(), point.getY());
        }
    }    
}
