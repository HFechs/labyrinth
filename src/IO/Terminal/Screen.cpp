#include "Screen.hpp"
#include "Painter.hpp"

using namespace App::Algs;
using namespace App::Game;

namespace App::IO::Terminal {
    Screen::~Screen() {
        endwin(); 
    }
    
    Screen::Screen() {
        //init ncurses
        WINDOW * mainwin;
        if ((mainwin = initscr()) == NULL) {
            perror("error initialising ncurses");
            exit(EXIT_FAILURE);
        }

        noecho();
        keypad(mainwin, TRUE);
        curs_set(0);
        cbreak();
        clear();
        timeout(1);
        
        //init color pairs
        if (has_colors()) {
            start_color();
            init_pair((int) ScreenColor::WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
            init_pair((int) ScreenColor::YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);
            init_pair((int) ScreenColor::BLACK_RED, COLOR_BLACK, COLOR_RED);
            init_pair((int) ScreenColor::GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
            init_pair((int) ScreenColor::RED_BLACK, COLOR_RED, COLOR_BLACK);
            init_pair((int) ScreenColor::BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
        }
    }     
   
    void Screen::echo(int x, int y, const char *text, ScreenColor color) {
        if (has_colors()) {
            attron(COLOR_PAIR((int) color));
        }
        
        mvprintw(y, x, text);
    }
    
    void Screen::drawScene(Scene &scene) {
        Painter painter = Painter(); 
        const size_t length = scene.length();
        
        for (size_t i = 0; i < length; i++) {
            Block block = scene.getBlockByIndex(i);
            BlockData blockData = std::any_cast<BlockData>(painter.draw(block));
            Point point = scene.calcXY(i);
            char buf[2] = {blockData.ch, '\0'};
            this->echo(point.getX(), point.getY(), buf, blockData.color);
        }
    } 
    
    void Screen::flip() {
        refresh();
    }
    
    unsigned int Screen::getWidth() {
        return COLS;
    }
    
    unsigned int Screen::getHeight() {
        return LINES;
    }
}
