
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define H (30)
#define W (60)
#define NR_GHOSTS (2)

struct coord{
	int x;
	int y;
};

struct pacman{
	struct coord c;
	int nx;
	int ny;
	int lives;
	int food;
};

struct ghost{
	struct coord c;
	int nx;
	int ny;
};
