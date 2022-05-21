CC= gcc
CFLAGS= -I -g -lncurses

end_file: pacman.o fleche.o
	$(CC) -o end_file pacman.c fleche.c $(CFLAGS)

sudoku.o: fleche.h fleche.c
	$(CC) sudoku.h sudoku.c $(CFLAGS)
