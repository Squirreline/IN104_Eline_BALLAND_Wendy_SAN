
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "structures.h"


struct Ghost all_the_ghosts[NB_GHOSTS];
struct PacMan PacMan = {{POS_X,POS_Y},0,0,LIVES,0};
char play_area[H][W] = {
	   { "############################################################" },
	   { "#                                                          #" },
	   { "#                                                          #" },
	   { "#        # # # # #          #             # # # # # #      #" },
	   { "#        #       #         # #            #                #" },
	   { "#        #       #        #   #           #                #" },
	   { "#        # # # # #       #     #          #                #" },
	   { "#        #              # # # # #         #                #" },
	   { "#        #             #         #        #                #" },
	   { "#        #            #           #       #                #" },
	   { "#        #           #             #      #                #" },
	   { "#        #          #               #     # # # # # #      #" },
	   { "#                                                          #" },
	   { "#                                                          #" },
	   { "#                                                          #" },
	   { "#        ##        ##           #          ##        #     #" },
	   { "#        # #      # #          # #         # #       #     #" },
	   { "#        #  #    #  #         #   #        #  #      #     #" },
	   { "#        #    # #   #        #     #       #   #     #     #" },
	   { "#        #     #    #       # # # # #      #    #    #     #" },
	   { "#        #          #      #         #     #     #   #     #" },
	   { "#        #          #     #           #    #      #  #     #" },
	   { "#        #          #    #             #   #       # #     #" },
	   { "#        #          #   #               #  #        ##     #" },
	   { "#                                                          #" },
	   { "#                                                          #" },
	   { "#                                                          #" },
	   { "#                                                          #" },
	   { "#                                                          #" },
	   { "############################################################" }
};


void print_field() {
	int i = 0;
	int j = 0;
	while (i<H) {
		while(j<W)  {
			printf("%c", play_area[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;

	}
	printf("\n");
}

void init() {
	int i = 0;
	int j = 1;
	play_area[POS_X][POS_Y] = 'P';
  srand(time(NULL));
	while (i<NB_GHOSTS) {

		int x = POS_X;
		int y = POS_Y;

		while (play_area[x][y] == '#' || ((x == POS_X) && (y == POS_Y))){
			x = (rand()%(H-2))+1;
			y = (rand()%(W-2))+1;
		}

		all_the_ghosts[i].c.x = x;
		all_the_ghosts[i].c.y = y;
		all_the_ghosts[i].nx = 0;
		all_the_ghosts[i].ny = 0;
		all_the_ghosts[i].food = 1;

    play_area[x][y] = 'G';

		i++;
	}

	i = 1;
	while (i<H) {
		while (j<W) {
			if (play_area[i][j] == ' ') {
				play_area[i][j] = '.';
			}
			j++;
		}
		j = 1;
		i++;
	}
}

bool check_lives() {

	if (PacMan.lives == 0) {
		printf("Plus de vies. Nourriture récoltée : %d\n", PacMan.food);
		return false;
	}

	else {
		printf("\n\nLives : %d\nFood : %d\n",PacMan.lives,PacMan.food);
		print_field();
		return true;
	}

}


void movePacman() {
	play_area[PacMan.c.x][PacMan.c.y] = ' ';

	if (play_area[PacMan.c.x+PacMan.nx][PacMan.c.y+PacMan.ny] == 'G'
		|| play_area[PacMan.c.x+PacMan.nx][PacMan.c.y+PacMan.ny] == '#') {

		printf("\nVous avez perdu une vie\n");
		PacMan.lives--;
		PacMan.c.x = POS_X;
		PacMan.c.y = POS_Y;
		play_area[POS_X][POS_Y] = 'P';
	}

	else {

		PacMan.c.x += PacMan.nx;
		PacMan.c.y += PacMan.ny;

		if (play_area[PacMan.c.x][PacMan.c.y] == '.') {
			PacMan.food++;

		}

		play_area[PacMan.c.x][PacMan.c.y] = 'P';
	}
}


void arrows() {
  char move;
	while (check_lives() == 1) {
		scanf("%c",&move);
		if (move == 'z' || move == 'q' || move == 's' || move == 'd') {
			if (move == 'z') {
				PacMan.ny = 0;
				PacMan.nx = -1;
			}

			if (move =='q') {
				PacMan.ny = -1;
				PacMan.nx = 0;
			}

			if (move == 's') {
				PacMan.ny = 0;
				PacMan.nx = 1;
			}

			if (move == 'd') {
				PacMan.ny = 1;
				PacMan.nx = 0;
			}
			int i = 0;
			int c = 0;
			int k;
			// On souhaite  ici choisir uniformément un mouvement parmi ceux qui sont possibles
			// c compte le nombre de mouvement, et t contient les mouvements possibles
			while (i < NB_GHOSTS) {
				int t[10] = {0,0,0,0,0,0,0,0,0,0};
				c = 0;
				if (play_area[all_the_ghosts[i].c.x][all_the_ghosts[i].c.y-1] != '#') {
					t[2*c+1] = -1;
					c++;

				}

				if (play_area[all_the_ghosts[i].c.x][all_the_ghosts[i].c.y+1] != '#') {
					t[2*c+1] = 1;
					c++;

				}

				if (play_area[all_the_ghosts[i].c.x-1][all_the_ghosts[i].c.y] != '#') {
					t[2*c] = -1;
					c++;

				}

				if (play_area[all_the_ghosts[i].c.x+1][all_the_ghosts[i].c.y] != '#') {
					t[2*c] = 1;
					c++;

				}

				k = rand()%c;

				if (all_the_ghosts[i].food == 1) {
					printf("\n");
					play_area[all_the_ghosts[i].c.x][all_the_ghosts[i].c.y] = '.';
				}

				else {
					play_area[all_the_ghosts[i].c.x][all_the_ghosts[i].c.y] = ' ';
				}

				all_the_ghosts[i].c.x += t[2*k];
				all_the_ghosts[i].c.y += t[2*k+1];

				if (play_area[all_the_ghosts[i].c.x][all_the_ghosts[i].c.y] == '.') {
					all_the_ghosts[i].food = 1;
				}

				else {
					all_the_ghosts[i].food = 0;
				}

				play_area[all_the_ghosts[i].c.x][all_the_ghosts[i].c.y] = 'G';

				i++;
			}

			movePacman();
		}
	}
}

int main() {

   srand(time(NULL));

   init();
   printf("\nPour vous déplacer : taper z/s/q/d puis entrée pour vous diriger respectivement haut/bas/gauche/droite \n Vous perdez une vie si vous rencontrez un G ou #");
   arrows();


}
