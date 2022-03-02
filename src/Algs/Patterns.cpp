#include "Patterns.hpp"

using namespace App::Game;

namespace App::Algs { 
    const size_t Patterns::SIZE = 4;
    
    Patterns::Patterns() {
        std::vector<App::Game::Scene> basePatterns;
        
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
                0,1,0,0,
                1,1,1,1,
                0,1,0,0,
                0,1,0,0
            })
        );
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
                1,0,0,0,
                0,1,1,0,
                0,1,1,0,
                0,0,0,1                
            })
        );
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
                0,1,0,1,
                0,1,1,0,
                0,1,0,0,
                1,0,0,1            
            })
        );
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
                1,1,0,0,
                1,1,0,0,
                0,0,0,1,
                0,0,1,1            
            })
        );
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
               1,1,0,0,
                0,1,0,0,
                0,1,1,1,
                0,0,0,1            
            })
        );
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
                1,0,0,1,
                0,1,0,0,
                0,0,1,0,
                1,0,0,1            
            })
        );
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
                1,1,1,0,
                0,0,1,0,
                0,0,1,0,
                1,0,1,1            
            })
        );
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
                1,1,0,0,
                0,0,1,0,
                1,0,1,0,
                1,0,0,1            
            })
        );
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
                0,1,0,1,
                1,0,0,1,
                1,1,1,0,
                1,0,0,1            
            })
        );
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
                1,0,0,1,
                1,1,1,1,
                0,0,0,0,
                1,1,1,1            
            })
        );
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
                1,0,0,0,
                1,1,0,1,
                1,1,0,1,
                0,0,0,1            
            })
        );
        basePatterns.push_back(
            Scene(Patterns::SIZE, std::vector<int>{
                0,1,0,1,
                0,1,0,0,
                0,1,1,1,
                0,0,0,0            
            })
        );
        
        for (Scene &pattern : basePatterns) {
            this->patterns.push_back(pattern);
            
            Scene tmp = pattern;
            SceneModify::leftRotate(tmp);
            this->patterns.push_back(tmp);
            
            tmp = pattern;
            SceneModify::rightRotate(tmp);
            this->patterns.push_back(tmp);
            
            tmp = pattern;
            SceneModify::leftRotate(tmp);
            SceneModify::verticalFlip(tmp);
            this->patterns.push_back(tmp);
            
            tmp = pattern;
            SceneModify::rightRotate(tmp);
            SceneModify::verticalFlip(tmp);
            this->patterns.push_back(tmp);
            
            tmp = pattern;
            SceneModify::verticalFlip(tmp);
            this->patterns.push_back(tmp);
            
            tmp = pattern;
            SceneModify::verticalFlip(tmp);
            SceneModify::horizontalFlip(tmp);
            this->patterns.push_back(tmp);
        }
    }
    
    size_t Patterns::count() {
        return this->patterns.size();
    }
    
    Scene Patterns::get(size_t n) {
        return this->patterns[n];
    }
}
