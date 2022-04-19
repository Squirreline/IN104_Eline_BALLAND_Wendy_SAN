#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"
#define dim (9)


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
		for (int j=y0;j<y0+3;y++){
			if (grid[i][j]==value){
				return false;
			}
		}
	}
	return true;
}

int** fill_grid(){
	/*On crée une grille vide*/
	srand(time(NULL));
	int** area = malloc(sizeof(int*)*dim);
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
				area[3*x + k][3*y + k] = n;
				printf("%d ",n);
			}
		printf("\n");
		}
	printf("\n");
	}
	/*Pour le remplissage des autres carrées, on procède ligne par ligne*/
	for (int y=0;y<dim;y++){
		for (int i=0;i<dim;i++){
			processed[i]=0;
		}
		for (int x=0;x<dim;x++){
			/*On isole le carré du haut déjà traité*/
			int c = 0;
			/*On ne traite pas les carrés diagonaux, on déclare simplement les entiers présents sur la ligne*/
			if (((x<=2)&&(y<=2))||((3<=x<=5)&&(3<=y<=5))||((6<=x<=8)&&(6<=y<=8))){
				processed[x+1]=1;
				c=c+1;
			} else {
				int n = rand()%dim+1;
				while ((processed[x+1]==1)&&(c!=dim)){
					n=rand()%dim +1;
				}
				if ((check_line(area,x,n))&&(check_column(area,y,n))&&(check_square(area,x,y,n))){
					c=c+1;
					processed[x+1]=1;
					area[x][y]=n;
				}
			}
		}
	}
	return area;
}

int main(){
	int** grille = fill_grid();
};
