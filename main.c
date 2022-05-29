#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

//Pour le sudoku
#include "check.h"
#include "erase.h"
#include "construction.h"
#include "play.h"
#define dim (9)

//Pour le pacman
#include "structures.h"
#include "pacman.h"

int main(){
	printf("Sélectionnez un jeu en saisissant un chiffre: sudoku (1) ou pacman (2)\n");
	int x;
	scanf("%d",&x);
	bool b=false; //Booléen qui nous indique si le chiffre saisi par l'utilisateur est valide
	while (!b){
		//Si le jeu choisi est le sudoku
		if (x==1){
			b = true;
			int** area = fill_grid();
			int difficulty;
    		printf("Choisissez votre difficulté : facile (1), intermédiaire (2), difficile (3)\n");
    		int n_values=0;
    		while (n_values==0){
      			scanf("%d",&difficulty);
      			if (difficulty==1){
        		n_values = 71;
        		} else if (difficulty==2){
        		n_values = 73;
        		} else if (difficulty==3){
        		n_values = 75;
        		} else {
        		printf("Format de difficulté incorrect, merci de préciser.\n");
        		}
    		}
			int** grid = erase_values(area,n_values);
			//display(grid);
			play(n_values,grid);
		};

		//Si le jeu choisi est pacman
		if (x==2){
			b = true;
			init();
			print_field();
   			printf("Utilisez une des touches suivantes pour vous déplacer : z (haut) s (bas) q (gauche) d (droite), suivie de la touche entrée.\n Pacman perd une vie dès qu'il rencontre un obstacle ou un fantôme.\n");
   			arrows();
		}
		else { //On traite le cas où l'utilisateur entre autre chose que 1 ou 2
		printf("Merci de saisir un chiffre entre 1 et 2.\n");
		scanf("%d",&x);
		}
	}
	return 0;
}
