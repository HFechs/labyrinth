#include "SceneModify.hpp"

using namespace App::Game;

namespace App::Algs {
    void SceneModify::modify(
        Scene &scene, 
        std::function<unsigned int(const unsigned int, const unsigned int, const unsigned int, const unsigned int)> calcX, 
        std::function<unsigned int(const unsigned int, const unsigned int, const unsigned int, const unsigned int)> calcY
    ) {
        const unsigned int width = scene.getWidth();
        const unsigned int height = scene.getHeight();
        if (width != height) {
            throw std::invalid_argument("scene has to be square");
        }
        
        Scene tmp = scene;
        size_t length = tmp.length();
        for (size_t i = 0; i < length; i++) {
            Point point = tmp.calcXY(i);
            const unsigned int x2 = calcX(point.getX(), point.getY(), width, height);
            const unsigned int y2 = calcY(point.getX(), point.getY(), width, height);
            scene.setBlock(tmp.getBlock(point.getX(), point.getY()), x2, y2);
        }
    }
    
    void SceneModify::leftRotate(Scene &scene) {
        SceneModify::modify(scene,
            []([[maybe_unused]] const unsigned int x, 
               const unsigned int y, 
               [[maybe_unused]] const unsigned int width,
               [[maybe_unused]] const unsigned int height) {
               return y;
            },
            [](const unsigned int x, 
                [[maybe_unused]] const unsigned int y, 
                [[maybe_unused]] const unsigned int width, 
                const unsigned int height) {
                return height - x - 1;
            });
    }
        
    void SceneModify::rightRotate(Scene &scene) {
        SceneModify::modify(scene,
            []( [[maybe_unused]] const unsigned int x, 
                const unsigned int y, 
                const unsigned int width,
                [[maybe_unused]] const unsigned int height) {
                return width - y - 1;
            },
            [](const unsigned int x, 
                [[maybe_unused]] const unsigned int y, 
                [[maybe_unused]] const unsigned int width, 
                [[maybe_unused]] const unsigned int height) {
                return x;
            });
    }
    
    void SceneModify::verticalFlip(Scene &scene) {
        SceneModify::modify(scene,
            [](const unsigned int x, 
                [[maybe_unused]] const unsigned int y, 
                [[maybe_unused]] const unsigned int width,
                [[maybe_unused]] const unsigned int height) {
                return x;
            },
            []([[maybe_unused]] const unsigned int x, 
               const unsigned int y, 
               [[maybe_unused]]const unsigned int width, 
               const unsigned int height) {
                return height - y - 1;
            });
    }
    
    void SceneModify::horizontalFlip(Scene &scene) {
        SceneModify::modify(scene,
            []( const unsigned int x, 
                [[maybe_unused]] const unsigned int y, 
                const unsigned int width,
                [[maybe_unused]] const unsigned int height) {
                return width - x - 1;
            },
            []( [[maybe_unused]] const unsigned int x, 
                const unsigned int y, 
                [[maybe_unused]] const unsigned int width, 
                [[maybe_unused]] const unsigned int height) {
                return y;
            });
    }
}
