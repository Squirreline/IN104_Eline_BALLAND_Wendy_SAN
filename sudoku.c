#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"
#define dim (9)

/* Create matrix 9*9
Create a function to fill all the diagonl 3*3 matrices randomly
Fill recursively the rest of the non-diagonal matrices:
	a) for every cell to be filled, we try all numbers until we find a safe number to be placed
	b) define a function that goes through the cell column and row to make sure that a number is safe in that position

Once the matrix is fully grilled, remove K elements randomly  to complete the game
	a) removing more elements will make the game harder, so you can create multiple difficulties (keep 10/matrix for easy, 8 for medium, 6 for hard)
	
Print out the matrix

By using scanf ask the user to fill a coordinate of a cell with a value from 1 to 9, if value is not in this range send error if it is, update board

*/

/* creer matrice () -> matrice remplie
remove (int K) -> matrice sans K éléments, ancienne matrice
afficher (matrice) -> void (affichage uniquement)
remplir (int n, int x, int y) -> void (affichage de la nouvelle matrice remplie)
*/

/*void display (int** matrix, int size);*/

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
		for (int j=y0;j<y0+3;y++){
			if (grid[i][j]==value){
				return false;
			}
		}
	}
	return true;
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
				area[x + 3*k][y + 3*k] = n;
				printf("%d ",n);
			}
		printf("\n");
		}
	printf("\n");
	}
	/*Pour le remplissage des autres carrés, on procède ligne par ligne*/
	for (int y=0;y<dim;y++){
		for (int i=0;i<dim;i++){
			processed[i]=0;
		}
		for (int x=0;x<dim;x++){
			int c = 0;
			/*On ne traite pas les carrés diagonaux, on déclare simplement les entiers présents sur la ligne*/
			if (((x<=2)&&(y<=2))||((3<=x<=5)&&(3<=y<=5))||((6<=x<=8)&&(6<=y<=8))){
				processed[area[x][y]-1]=1;
				c=c+1;
			} else {
				int n = rand()%dim+1;
				while ((processed[area[x][y]-1]==1)&&(c!=dim)){
					n=rand()%dim +1;
				}
				if ((check_line(area,x,n))&&(check_column(area,y,n))&&(check_square(area,x,y,n))){
					c=c+1;
					processed[area[x][y]-1]=1;
					area[x][y]=n;
				}
			}
		}
	}
	return area;
}




int main(){
	int** grille = fill_grid();
	display(grille);
};

	






