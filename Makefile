include config.mk

VPATH = src

all: buttermilk

buttermilk.o: buttermilk.c buttermilk.h config.h
	${CC} -g -c -O2 -Wall ${VTEFLAGS} src/buttermilk.c

config.o: config.c config.h
	${CC} -g -c -O2 -Wall ${VTEFLAGS} src/config.c

buttermilk: buttermilk.o config.o
	${CC} -g -o $@ buttermilk.o config.o ${VTELIBS} ${INIHLIBS} -g

clean:
	rm -f buttermilk buttermilk.o config.o

install: all
	install -Dm755 buttermilk -t ${DESTDIR}${PREFIX}/bin
	install -Dm644 buttermilk.desktop -t ${DESTDIR}${PREFIX}/share/applications

uninstall:
	rm -v ${DESTDIR}${PREFIX}/bin/buttermilk
	rm -v ${DESTDIR}${PREFIX}/share/applications/buttermilk.desktop

.PHONY: all clean install uninstall
