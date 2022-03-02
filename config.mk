#PREFIX je defaultne relativni, adresar s hrou je "portable"
#jde nastavit fixni (/opt/game) nebo treba /usr/local/
PREFIX=../

CC=g++

CFLAGS=-g -O2 -pedantic --std=c++17 -Wall -Wextra $(shell pkg-config --cflags ncurses)
LDFLAGS=$(shell pkg-config --libs ncurses) -lm
VERSION=0.1
PROGRAM=labyrinth

FLAGS=-DPREFIX_F=\"$(PREFIX)\" -DVERSION_F=\"$(VERSION)\"

%.o : %.cpp
	$(CC) $(CFLAGS) ${FLAGS} ${LIBS} -c $< -o $*.o
