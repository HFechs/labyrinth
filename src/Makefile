include ../config.mk

OBJ=main.o \
	IO/Terminal/Screen.o IO/Terminal/Events.o IO/Terminal/Painter.o \
	Game/Main.o Game/Block.o Game/Scene.o Game/Enemy.o \
	Algs/Point.o Algs/Patterns.o Algs/Labyrinth.o Algs/SceneModify.o Algs/defines.o Algs/Explorer.o \
	Algs/PathVisualizer.o Algs/Digger.o Algs/Tunneler.o Algs/Fps.o
	
HEAD=globals.h \
	IO/IScreen.hpp IO/IEvents.hpp IO/IPainter.hpp \
	IO/Terminal/Screen.hpp IO/Terminal/Events.hpp IO/Terminal/Painter.hpp \
	Game/Main.hpp Game/Block.hpp Game/Scene.hpp Game/Enemy.hpp \
	Algs/Point.hpp Algs/Patterns.hpp Algs/Labyrinth.hpp Algs/SceneModify.hpp Algs/Explorer.hpp \
	Algs/PathVisualizer.hpp Algs/Digger.hpp Algs/Tunneler.hpp Algs/Fps.hpp

all: ${PROGRAM}

clean:
	find . -iname "*.o" -delete
	rm ${PROGRAM}
	@echo "Done"

${PROGRAM}: ${OBJ}
	${CC} ${OBJ} -o ${PROGRAM} ${OPT} ${LDFLAGS}

${OBJ}: ${HEAD}
