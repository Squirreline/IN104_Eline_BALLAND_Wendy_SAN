#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"
#define dim (9)


<<<<<<< HEAD
=======
/*Fonction qui nous indique si on peut insérer l'entier sur la ligne*/
>>>>>>> 85d836653e4db8516c044a510447c596068c531f
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
				printf("%d ",n);
			}
		printf("\n");
		}
	printf("\n");
	}
	/*Remplissage récursif des autres cases*/
	bool b = rec_fill(area);
}


int main(){
	int** grille = fill_grid();
};
