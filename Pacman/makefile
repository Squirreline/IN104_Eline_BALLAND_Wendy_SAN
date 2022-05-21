CC= gcc
CFLAGS= -I -g
LDLIBS= -lncurses

end_file: pacman.o fleche.o main.o
	$(CC) -o end_file pacman.o fleche.o main.o $(LDLIBS)

pacman.o: pacman.c
	$(CC) -c pacman.c $(CFLAGS)

fleche.o: fleche.c fleche.h
	$(CC) -c fleche.c $(CFLAGS)

main.o: main.c structures.h
	$(CC) -c main.c $(CFLAGS)
