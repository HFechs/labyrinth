include config.mk

all: 
	rm -f .*.swp
	make -C src

clean: 
	make -C src clean

#davat jen kdyz je PREFIX neco jineho nez ../ ;-)
install: all
	strip src/${PROGRAM}
	mkdir -p ${PREFIX}/bin
#	mkdir -p ${PREFIX}/share
	install -c src/labyrinth ${PREFIX}/bin
#	install -c share/* ${PREFIX}/share/*
