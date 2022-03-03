#pragma once
#include <cstddef>
#include <vector>
#include <map>
#include <algorithm>
#include "../Game/Scene.hpp"
#include "defines.hpp"

namespace App::Algs {
    typedef std::map<unsigned int, unsigned int> ExplorerRating;
    
    enum class ExplorerReturn {
        FOUND,
        NOT_FOUND_TRAP,
        NOT_FOUND_LOOP,
        NOT_FOUND_START,
        NOT_FOUND_LIMIT,
        EOE
    };
    
    class Explorer
    {
        private:
            Explorer();
            
        public:
            static const unsigned int MAX_LOOP;
            static ExplorerReturn explore(App::Game::Scene &scene, Point start, Point end, Path &path);
            static ExplorerReturn explore(App::Game::Scene &scene, Point start, Point end, Path &explored, Path &path);
            static ExplorerReturn explore(App::Game::Scene &scene, Point start, Point end, Point position, ExplorerRating &rating, const unsigned int limit, Path &path);
            static ExplorerReturn explore(App::Game::Scene &scene, Point start, Point end, Point position, Path &explored, ExplorerRating &rating, const unsigned int limit, Path &path);
            static bool isPointWalkable(App::Game::Scene &scene, signed int x, signed int y, Path &explored);
    };
}
