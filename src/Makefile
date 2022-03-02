include ../config.mk

OBJ=main.o \
    IO/Terminal/Screen.o IO/Terminal/Events.o IO/Terminal/Painter.o \
    Game/Main.o Game/Block.o Game/Scene.o \
	Algs/Point.o Algs/Patterns.o Algs/Labyrinth.o Algs/SceneModify.o
	
HEAD=globals.h \
     IO/IScreen.hpp IO/IEvents.hpp IO/IPainter.hpp \
     IO/Terminal/Screen.hpp IO/Terminal/Events.hpp IO/Terminal/Painter.hpp \
	 Game/Main.hpp Game/Block.hpp Game/Scene.hpp \
	 Algs/Point.hpp Algs/Patterns.hpp Algs/Labyrinth.hpp Algs/SceneModify.hpp

all: ${PROGRAM}

clean:
	find . -iname "*.o" -delete
	rm ${PROGRAM}
	@echo "Done"

${PROGRAM}: ${OBJ}
	${CC} ${OBJ} -o ${PROGRAM} ${OPT} ${LDFLAGS}

${OBJ}: ${HEAD}
