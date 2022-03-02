#include "globals.h"

#include <iostream>
#include "Game/Main.hpp"
#include "IO/Terminal/Screen.hpp"
#include "IO/Terminal/Events.hpp"

using namespace App::Game;
using namespace App::IO::Terminal;

int main() {
    Screen screen = Screen();
    Events events = Events();
    Main main = Main(screen, events);
    main.loop();
    return 0;
}
