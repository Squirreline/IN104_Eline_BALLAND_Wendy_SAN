#include "check.h"


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
