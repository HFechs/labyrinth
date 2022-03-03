#include "Explorer.hpp"

using namespace App::Game;

namespace App::Algs {
    const unsigned int Explorer::MAX_LOOP = 10000;
    
    ExplorerReturn Explorer::explore(Scene &scene, Point start, Point end, Path &path) {
        Path explored;
        ExplorerRating rating;
        return Explorer::explore(scene, start, end, start, explored, rating, 0, path);
    }
    
    ExplorerReturn Explorer::explore(Scene &scene, Point start, Point end, Path &explored, Path &path) {
        ExplorerRating rating;
        return Explorer::explore(scene, start, end, start, explored, rating, 0, path);
    }
    
    ExplorerReturn Explorer::explore(App::Game::Scene &scene, Point start, Point end, Point position, ExplorerRating &rating, const unsigned int limit, Path &path) {
        Path explored;
        return Explorer::explore(scene, start, end, position, explored, rating, limit, path);
    }
    
    ExplorerReturn Explorer::explore(App::Game::Scene &scene, Point start, Point end, Point position, Path &explored, ExplorerRating &rating, const unsigned int limit, Path &path) {
        Direction direction = Direction::RIGHT;
        signed int x = position.getX();
        signed int y = position.getY();
        unsigned int ratingOfEndByStart = 0;
        auto &VX = DirectionV::getVX();
        auto &VY = DirectionV::getVY();
        
        if (std::find(path.begin(), path.end(), start.getXY()) == path.end()) {
            path.push_back(start.getXY());
        }
        if (std::find(path.begin(), path.end(), position.getXY()) == path.end()) {
            path.push_back(position.getXY());
        }        
        
        for (unsigned int counter = 0; counter < Explorer::MAX_LOOP; counter++) {
            if (limit && counter == limit) {
                return ExplorerReturn::NOT_FOUND_LIMIT;
            }
            
            const unsigned int xy = Point(x, y).getXY();
            auto search = rating.find(xy);
            const unsigned int currentRating = search != rating.end() ? search->second : 1;
            unsigned int minRating = currentRating;
            Direction minRatingDirection = direction;
            bool foundWalkable = false;
            bool foundDirection = false;
            
            for (int i = 0; i < 4; i++) {
                const signed int x2 = x + VX[(size_t) direction];
                const signed int y2 = y + VY[(size_t) direction];
                
                if (Explorer::isPointWalkable(scene, x2, y2, explored)) {
                    foundWalkable = true;
                    
                    const unsigned int xy2 = Point(x2, y2).getXY();
                    auto search = rating.find(xy2);
                    const unsigned int directionRating = search != rating.end() ? search->second : 1;
                    
                    if (minRating > directionRating || !foundDirection) {
                        foundDirection = true;
                        minRating = directionRating;
                        minRatingDirection = direction;
                    }
                }
                
                direction = (Direction) (((size_t) direction + 1) % 4);
            }
            
            if (!foundWalkable) {
                return ExplorerReturn::NOT_FOUND_TRAP;
            }
            
            if (ratingOfEndByStart && ratingOfEndByStart <= minRating) {
                return ExplorerReturn::NOT_FOUND_START;
            }
            
            direction = minRatingDirection;
            x = x + VX[(size_t) direction];
            y = y + VY[(size_t) direction];
            
            if ((unsigned int) x == start.getX() && (unsigned int) y == start.getY()) {
                ratingOfEndByStart = currentRating;
            } else {
                ratingOfEndByStart = 0;
            }
            
            rating[xy] = currentRating + 1;
                    
            const unsigned int xy2 = Point(x, y).getXY();
            if (std::find(path.begin(), path.end(), xy2) == path.end()) {
                path.push_back(xy2);
            }
            if ((unsigned int) x == end.getX() && (unsigned int) y == end.getY()) {
                return ExplorerReturn::FOUND;
            }
        }
        
        return ExplorerReturn::NOT_FOUND_LOOP;
    }
    
    bool Explorer::isPointWalkable(App::Game::Scene &scene, signed int x, signed int y, Path &explored) {
        if ((unsigned int) x >= scene.getWidth() || (unsigned int) y>= scene.getHeight() || x < 0 || y <0) {
            return false;
        }
        
        if (!scene.getBlock(x, y).isWalkable()) {
            return false;
        }
        
        if (std::find(explored.begin(), explored.end(), Point(x, y).getXY()) != explored.end()) {
            return false;
        }
        
        return true;
    }
}
