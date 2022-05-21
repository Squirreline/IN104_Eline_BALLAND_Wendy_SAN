#include "sudoku.h"

// fonction pour créer une nouvelle grille qui sera la grille proposée au joueur, avec quelques valeurs effacée.
// n_values est le nombre de valeurs effacées
int ** erase_values(int ** grid, int n_values){
  srand(time(NULL));

  // on copie la grille complète dans la nouvelle grille
  int ** play_grid =  malloc(sizeof(int*)*dim);
  for (int i=0;i<dim;i++) {
 		play_grid[i]=malloc(sizeof(int)*dim);
    for (int j=0;j<dim;j++){
      play_grid[i][j] = grid[i][j];
    }
 	}
  // on génère aléatoirement les coordonnées des valeurs qui seront effacées
  int x, y;
  for (int i = 0; i<n_values; i++){
    x = rand()%dim;
    y = rand()%dim;
    play_grid[x][y] = 0;
  }
  return play_grid;
}
