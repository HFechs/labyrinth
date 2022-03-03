#include "Labyrinth.hpp"

using namespace App::Game;

namespace App::Algs {
    void Labyrinth::generate(Scene &scene) {
        Patterns patterns;
        const unsigned int pcount = patterns.count();

        for (unsigned int y = 0; y < scene.getHeight() / 4; y++) {
            for (unsigned int x = 0; x < scene.getWidth() / 4; x++) {
                const unsigned int n = rand() % pcount;
                const Scene pattern = patterns.get(n);
                scene.putScene(pattern, x * Patterns::SIZE, y * Patterns::SIZE);
            }
        }            
    }
}
