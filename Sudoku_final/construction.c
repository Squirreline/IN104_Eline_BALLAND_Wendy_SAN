#include "construction.h"
#include "check.h"

// fonction d'affichage de la grille
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
// remplissage récursif de la grille sans les trois carrés diagonaux
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


// remplissage de la grille entière

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
