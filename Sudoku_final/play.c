#include "play.h"
#include "erase.h"

void play(int n_values){
  int ** grid = fill_grid();
  int ** play_grid = erase_values(grid, n_values);
  int n_play = 0; // compteur du nombre de case remplies par le joueur
  int line, column, value;
  bool good_grid = true;

  while (n_play<n_values){
    display(play_grid);
    printf("\nIndiquez votre nombre sous la forme : ligne (0-8) colonne (0-8) valeur (1-9). Ex : 0 2 3\n");
    scanf("%d %d %d", &line,&column,&value);
    printf("\n");
    if (play_grid[line][column] !=0){
    	printf("Cette case est déjà remplie\n\n");
    } else {
    	if (grid[line][column] != value){
      	good_grid = false;
    	}
    	play_grid[line][column] = value;
    	n_play +=1;
  	}
  }
  if (good_grid) {
    printf("Bravo vous avez rempli la grille!\n");
  }
  else {
    printf("La grille n'est pas bonne.\n");
  }
}
