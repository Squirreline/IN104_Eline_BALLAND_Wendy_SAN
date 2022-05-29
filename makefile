CC= gcc
CFLAGS= -I -g

end_file: pacman.o play.o erase.o construction.o check.o main.o
	$(CC) -o end_file pacman.o main.o $(CFLAGS)

play.o: play.c play.h
	$(CC) -c play.c $(CFLAGS)

erase.o: erase.c erase.h
	$(CC) -c erase.c $(CFLAGS)

construction.o: construction.c construction.h
	$(CC) -c construction.c $(CFLAGS)

check.o: check.c check.h
	$(CC) -c check.c $(CFLAGS)

pacman.o: pacman.c
	$(CC) -c pacman.c $(CFLAGS)

main.o: main.c structures.h
	$(CC) -c main.c $(CFLAGS)
