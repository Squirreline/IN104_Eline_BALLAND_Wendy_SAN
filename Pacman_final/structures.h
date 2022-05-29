#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

#define H 30
#define W 60
#define NB_GHOSTS 5
#define LIVES 3
#define POS_X 1
#define POS_Y 1


struct coord {
	int x;
	int y;
};

struct PacMan {
	struct coord c;
	int nx;
	int ny;
	int lives;
	int food;
};

struct Ghost {
	struct coord c;
	int nx;
	int ny;
	int food;
// structure ghost modifiée : on se sert du dernier paramètre pour se souvenir si le fantome était sur de la nourriture ou pas
};
