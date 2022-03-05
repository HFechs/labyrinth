#include <iostream>
#include "Main.hpp"
#include "../IO/Terminal/Screen.hpp"
#include "../Algs/Labyrinth.hpp"
#include "../Algs/Explorer.hpp"
#include "../Algs/PathVisualizer.hpp"
#include "../Algs/defines.hpp"
#include <unistd.h>

using namespace App::Algs;
using namespace App::Game;
using namespace App::IO;
using namespace App::IO::Terminal;

namespace App::Game {
    void Main::generateScene(Scene &scene, unsigned int width, unsigned int height) {
        Path path;
        
        while ( true ) {
            Labyrinth::generate(scene);
            Tunneler::dig(scene, Point(0, height - 1), Point(width - 1, 0));
            if (Tunneler::dig(scene, Point(0, 0), Point(width - 1, height - 1)) != TunnelerReturn::FOUND) {
                continue;
            }
            path.clear();
            if (Explorer::explore(scene, Point(width - 1, height - 1), Point(0, 0), path) == ExplorerReturn::FOUND) {
                break;
            }
        }
        
        PathVisualizer::visualize(scene, path, Block(BlockType::DEBUG1));
    }
    
    Main::Main(IScreen &screen, IEvents &events): screen(screen), events(events) {
        srand((unsigned) time(NULL));
    }
    
    void Main::loop() {
        //@TODO - az bude vice vystupu, je to treba predelat
        Screen &tscreen = dynamic_cast<Screen&>(this->screen);
        
        const unsigned int patternSize = 4;
        const unsigned int width = (tscreen.getWidth() / patternSize) * patternSize;
        const unsigned int height = (tscreen.getHeight() / patternSize) * patternSize;  
        
        Scene scene(width, height);
        Main::generateScene(scene, width, height);
        Enemy enemy(scene, Point(width - 1, height - 1), Point(0, 0));
        
        tscreen.drawScene(scene);
        tscreen.flip();
        
        while (true) {
            int value;
            Event e = this->events.get(value);
            if (e != Event::NONE) {
                break;
                char buf[1024];
                sprintf(buf, "%i %i %i %i", width, height, (int) e, value);
                tscreen.echo(0, 0, buf);
                tscreen.flip();
            }
            
            if (enemy.step()) {
                tscreen.drawScene(scene);
                tscreen.flip();
            }
        }
    }
    
    Main::~Main() {}
}
