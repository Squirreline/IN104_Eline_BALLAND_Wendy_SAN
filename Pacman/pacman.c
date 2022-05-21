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





void init(struct ghost* all_the_ghosts){
	for (int i=0;i<W;i++){
		for (int j=0;j<H;j++){
			if (play_area[i][j]==' '){
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
		all_the_ghosts[i].c.x = x;
		all_the_ghosts[i].c.y = y;
		all_the_ghosts[i].nx = 0;
		all_the_ghosts[i].ny = 0;

		play_area[x][y] = 'G';
	}

}

/*void keyboard(struct pacman PACMAN){
}*/

void movePacman(struct pacman* PACMAN){
	//Deleting Pacman from old position
	play_area[PACMAN->c.x][PACMAN->c.y] = ' ' ;
	//Computing new desired coordinates
	int nx = PACMAN->nx + PACMAN->c.x ;
	int ny = PACMAN->ny + PACMAN->c.y ;
	//Testing whether or not there is a wall
	if (play_area[nx][ny]=='#'){
		PACMAN->nx = 0 ;
		PACMAN->ny = 0 ;
	}
	if (play_area[nx][ny]=='G'){
		PACMAN->lives +=-1 ;
		PACMAN->c.x = 1 ;
		PACMAN->c.y = 1 ;
	} else {
		if (play_area[nx][ny]=='.'){
			PACMAN->food += 1;
		}
		PACMAN->c.x += nx ;
		PACMAN->c.y += ny ;
	}
}


void check_lives(struct pacman* PACMAN){
	if (PACMAN->lives<0){
		printf("No more lives. Food collected : %d\n",PACMAN->food);
	} else {
		for (int i=0; i<H; i++){
			for (int j=0; j<W; j++){
				printf("%s",play_area[i][j]);
			}
			printf("\n");
		}
	}
}
