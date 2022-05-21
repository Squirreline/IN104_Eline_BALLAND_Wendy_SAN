#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "fleche.h"
int main(){
	/*struct ghost allGhosts[NR_GHOSTS];*/
  	/* Initialisation du pacman*/
	struct pacman* PACMAN;
	PACMAN->c.x = 1;
	PACMAN->c.y = 1;
	PACMAN->nx = 0;
	PACMAN->ny = 0;
	PACMAN->lives = 3;
	PACMAN->food = 0;
	struct ghost* all_the_ghosts = malloc(sizeof(struct ghost)*NR_GHOSTS);
	/*Defining the playing area*/

}
