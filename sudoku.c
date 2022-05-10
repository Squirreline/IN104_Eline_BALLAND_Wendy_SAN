#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"
#include "erase.h"
#define dim (9)


/*Fonction qui nous indique si on peut insérer l'entier sur la ligne*/
bool check_line(int** grid, int line, int value){
	for (int i=0;i<dim;i++){
		if (grid[line][i]==value){
			return false;
		}
	}
	return true;
}
			
/*Fonction qui nous indique si on peut insérer l'entier sur la colonne*/
bool check_column(int** grid, int column, int value){
	for (int i=0;i<dim;i++){
		if (grid[i][column]==value){
			return false;
		}
	}
	return true;
}


/*Fonction qui nous indique si on peut insérer l'entier dans le carré 3*3*/
bool check_square(int** grid, int x, int y, int value){
	/*On cherche (x0,y0) coordonnées du coin supérieur gauche de notre carré 3*3 pour le parcourir*/
	int x0 = (int)(x/3)*3;
	int y0 = (int)(y/3)*3;
	for (int i=x0;i<x0+3;i++){
		for (int j=y0;j<y0+3;j++){
			if (grid[i][j]==value){
				return false;
			}
		}
	}
	return true;
}

bool is_allowed(int** grid, int x, int y, int value){
	bool b1 = check_line(grid,x,value);
	bool b2 = check_column(grid,y,value);
	bool b3 = check_square(grid,x,y,value);
	return ((b1&&b2)&&b3);
}

void display(int** grid){
		for (int x=0;x<dim;x++){
			for (int y=0;y<dim;y++){
				if ((y%3==0)&&(y+1<dim)&&(y!=0)){
					printf("| ");
				}
				printf("%d ",grid[x][y]);
			}
			printf("\n");
			if (((x+1)%3==0)&&(x!=dim-1)){
				printf("----------------------\n");
			}
		}
		printf("\n");
		
}

bool rec_fill(int** area){
	for (int x=0;x<9;x++){
		for (int y=0;y<9;y++){
			if (area[x][y]==0){
				for (int n=1;n<=9;n++){
					if (is_allowed(area,x,y,n)){
						area[x][y]=n;
						if (rec_fill(area)){
							return true;
						} else {
							area[x][y]=0;
						}
					}
				}
			return false;
			}
		}
	}
	return true;
}



int** fill_grid(){
	/*On crée une grille vide*/
	int** area = malloc(sizeof(int*)*dim);
	srand(time(NULL));
	//int** area = malloc(sizeof(int*)*dim);
	for (int i=0;i<dim;i++) {
		area[i]=malloc(sizeof(int)*dim);
	}
	/*On remplit les blocs diagonaux, indépendants entre eux*/
	int processed[dim];
	for (int k=0;k<=2;k++){
	/*On initialise le tableau des nombres traités*/
		for (int i=0;i<dim;i++){
			processed[i]=0;
		}
		int c =0;
		for (int x=0;x<=2;x++){
			for (int y=0;y<=2;y++){
				int n = rand()%dim +1;
				while ((processed[n-1]==1)&&(c!=dim)){
					n=rand()%dim +1;
				}
				processed[n-1]=1;
				c=c+1;
				area[x + 3*k][y + 3*k] = n;
			}
		}
	}
	/*Remplissage récursif des autres cases*/
	bool b = rec_fill(area);
	return area;
}

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

int main(){
	int** area = fill_grid();
	//display(area);
	int difficulty;
    printf("Choisissez votre difficulté : facile (1), intermédiaire (2), difficile (3)\n");
    int n_values=0;
    while (n_values==0){
      scanf("%d",&difficulty);
      if (difficulty==1){ n_values = 71;}
      else if (difficulty==2){ n_values = 73;}
      else if (difficulty==3){ n_values = 75;}
      else { printf("Format de difficulté incorrect, merci de préciser.\n");}
    }
	int** grid = erase_values(area,n_values);
	display(grid);
	play(n_values);
};

	





