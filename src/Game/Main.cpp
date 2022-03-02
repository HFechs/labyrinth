#include "Main.hpp"
#include "../IO/Terminal/Screen.hpp"
#include "../Algs/Labyrinth.hpp"

using namespace App::Algs;
using namespace App::Game;
using namespace App::IO;
using namespace App::IO::Terminal;

namespace App::Game {
    Main::Main(IScreen &screen, IEvents &events): screen(screen), events(events) {
        srand((unsigned) time(NULL));
    }
    
    void Main::loop() {
        //@TODO - az bude vice vystupu, je to treba predelat
        Screen &tscreen = dynamic_cast<Screen&>(this->screen);
        
        const unsigned int patternSize = 4;
        const unsigned int width = (tscreen.getWidth() / patternSize) * patternSize;
        const unsigned int height = (tscreen.getHeight() / patternSize) * patternSize;  
        
        Scene scene = Scene(width, height);
        Labyrinth::generate(scene);
        scene.setBlock(Block(BlockType::START), 0, 0);
        
        tscreen.drawScene(scene);
        tscreen.flip();
        
        while (true) {
            int value;
            Event e = this->events.get(value);
            if (e != Event::NONE) {
                char buf[1024];
                sprintf(buf, "%i %i %i %i", width, height, (int) e, value);
                tscreen.echo(0, 0, buf);
                tscreen.flip();
            }
        }
    }
    
    Main::~Main() {}
}
