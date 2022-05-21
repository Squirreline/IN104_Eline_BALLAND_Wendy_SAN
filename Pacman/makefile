CC= gcc
CFLAGS= -I -g -lncurses

end_file: pacman.o fleche.o
	$(CC) -o end_file pacman.c fleche.c $(CFLAGS)

fleche.o: fleche.h fleche.c
	$(CC) -o fleche.o fleche.h fleche.c $(CFLAGS)
