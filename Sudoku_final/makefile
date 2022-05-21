CC= gcc
CFLAGS= -I -g


end_file: play.o erase.o construction.o check.o main.o
	$(CC) -o end_file play.o erase.o construction.o check.o main.o $(LDLIBS)

play.o: play.c play.h
	$(CC) -c play.c $(CFLAGS)

erase.o: erase.c erase.h
	$(CC) -c erase.c $(CFLAGS)

construction.o: construction.c construction.h
	$(CC) -c construction.c $(CFLAGS)

check.o: check.c check.h
	$(CC) -c check.c $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)
