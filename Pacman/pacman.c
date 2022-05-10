#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"

char play_area[H][W] =
{
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


/* Initialisation du pacman*/
struct pacman PACMAN = {{1,1}, 0, 0, 3, 0};

void init(){
	for (int i=0;i<W;i++){
		for (int j=0;j<H;j++){
			if (play_area[i][j]=' '){
				play_area[i][j]='.';
			}
		}
	}
	srand(time(NULL));
	for (int i=0;i<NR_GHOSTS;i++){
		int x = 1;
		int y = 1;
		while (play_area[x][y]!='.'){
			int x = rand()%(W-1) + 1;
			int y = rand()%(H-1) +1;
		}
		NR_GHOSTS[i].c.x = x;
		NR_GHOSTS[i].c.y = y;
		NR_GHOSTS[i].vx = 0;
		NR_GHOSTS[i].vy = 0;
		play_area[x][y] = 'G';
	}

}

/*void keyboard(struct pacman PACMAN){
}*/

void movePacman(struct pacman PACMAN){
	//Deleting Pacman from old position
	play_area[PACMAN.c.x][PACMAN.c.y] = ' ' ;
	//Computing new desired coordinates
	int nx = PACMAN.nx + PACMAN.x ;
	int ny = PACMAN.ny + PACMAN.y ;
	//Testing whether or not there is a wall
	if (play_area[nx][ny]=='#'){
		PACMAN.nx = 0 ;
		PACMAN.ny = 0 ;
	}
	if (play_area[nx][ny]=='G'){
		PACMAN.lives +=-1 ;
		PACMAN.c.x = 1 ;
		PACMAN.c.y = 1 ;
	} else {
		if (play_area[nx][ny]=='.'){
			PACMAN.food += 1;
		}
		PACMAN.c.x += nx ;
		PACMAN.c.y += ny ;
	}
}


void check_lives(struct pacman PACMAN){
	if (PACMAN.lives<0){
		printf("No more lives. Food collected : %d\n",PACMAN.food);
	} else {
		for (int i=0; i<H; i++){
			for (int j=0; j<W; j++){
				printf("%s",play_area[i][j]);
			}
			printf("\n");
		}
	}
}



int main(){
	/*struct ghost allGhosts[NR_GHOSTS];*/
	struct pacman PACMAN;
	/*Defining the spawning point*/
	//PACMAN.c.x = 1;
	/*PACMAN->c->y = 1;
	PACMAN->nx = 0;
	PACMAN->ny = 0;
	PACMAN->lives = 0;
	PACMAN->food = 0;*/
	/*Defining the playing area*/
	char* fleche;
	fscanf("%s",fleche);
	printf("%s",fleche);
}