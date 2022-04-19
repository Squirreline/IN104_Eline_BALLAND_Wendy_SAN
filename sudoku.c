#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"
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
			/*On ne traite pas les carrés diagonaux, on déclare simplement les entiers déjà présents sur la ligne*/
			if (((x<=2)&&(y<=2))||((3<=x)&&(x<=5)&&(3<=y)&&(y<=5))||((6<=x)&&(x<=8)&&(6<=y)&&(y<=8))){
				processed[area[x][y]-1]=1;
			}
			int n = rand()%dim+1;
			bool res=false; /*Booléen qui nous indique si la case a pu être remplie*/
			printf("f\n");
			while (res==false){
				printf("f\n");
				if ((processed[n-1]==0)&&(check_line(area,x,n))&&(check_column(area,y,n))&&(check_square(area,x,y,n))){
					processed[n-1]=1;
					printf("f\n");
					area[x][y]=n;
					res=true;

				}
				n=rand()%dim+1;
			
			}
		}
	}
	return area;
}




int main(){
	int** grille = fill_grid();
	display(grille);
};

	






