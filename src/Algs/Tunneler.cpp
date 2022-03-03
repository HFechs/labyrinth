#include "Tunneler.hpp"

using namespace App::Game;

namespace App::Algs {
    const unsigned int Tunneler::MAX_LOOP = 100;
    
    TunnelerReturn Tunneler::dig(App::Game::Scene &scene, Point start, Point end) {
        Point positions[2] = {start, end};
        Point ends[2] = {end, start};
        Path explored[2];
        
        scene.setBlock(Block(BlockType::PATH), start.getX(), start.getY());
        scene.setBlock(Block(BlockType::PATH), end.getX(), end.getY());
        
        for (unsigned int counter = 0; counter < Tunneler::MAX_LOOP; counter++) {
            for (int i = 0; i < 2; i++) {
                const DiggerReturn dret = Digger::dig(scene, positions[i], ends[i], explored[i]);
                switch (dret) {
                    case DiggerReturn::FOUND:
                        return TunnelerReturn::FOUND;
                        break;
                    
                    case DiggerReturn::NOT_FOUND_TRAP:
                        explored[i].clear();
                        break;
                        
                    default:
                        break;
                }
            }
        }
        
        return TunnelerReturn::NOT_FOUND_LOOP;
    }
}
