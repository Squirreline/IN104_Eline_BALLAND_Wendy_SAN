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
