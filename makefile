CC= gcc
CFLAGS= -I -g
end_file: erase.o sudoku.o
	$(CC) -o end_file erase.c sudoku.c $(CFLAGS)
