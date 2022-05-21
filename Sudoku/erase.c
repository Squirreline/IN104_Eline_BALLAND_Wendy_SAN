#include "sudoku.h"

// fonction pour créer une nouvelle grille qui sera la grille proposée au joueur, avec quelques valeurs effacée.
// n_values est le nombre de valeurs effacées
int ** erase_values(int ** grid, int n_values){
  srand(time(NULL));

  // on copie la grille complète dans la nouvelle grille
  int ** play_grid =  malloc(sizeof(int*));
  for (int i=0;i<dim;i++) {
 		play_grid[i]=malloc(sizeof(int));
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

/*void play(int n_values){
  int ** grid = fill_grid();
  int ** play_grid = erase_values(grid, n_values);
  int n_play = 0; // compteur du nombre de case remplies par le joueur
  int line, column, value;
  bool good_grid = true;

  while (n_play<=n_values){
    display(play_grid);
    printf("\nIndiquez votre nombre sous la forme :(ligne colonne valeur ). Ex : 0 2 3");
    scanf("%d %d %d", &line,&column,&value);
    if (grid[line][column] != value){
      good_grid = false;
    }
    play_grid[line][column] = value;
    n_play +=1;
  }
  if (good_grid) {
    printf("Bravo vous avez rempli la grille");
  }
  else {
    printf("La grille n'est pas bonne");
  }
}*/
