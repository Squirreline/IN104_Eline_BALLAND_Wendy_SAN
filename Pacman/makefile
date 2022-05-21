CC= gcc
CFLAGS= -I -g
LDLIBS= -lncurses

end_file: pacman.o fleche.o structures.o main.o
	$(CC) -o end_file pacman.c fleche.c main.c structures.h $(CFLAGS)

fleche.o: fleche.c fleche.h
	$(CC) -o fleche.o fleche.c fleche.h $(CFLAGS)

main.o: main.c structures.h
	$(CC) -o main.o main.c structures.h $(CFLAGS)
