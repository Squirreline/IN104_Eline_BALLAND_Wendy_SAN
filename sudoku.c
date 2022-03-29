#include <stdio.h>
#include <stdlib.h>
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

int** fill_grid(){
	/*On crée une grille vide*/
	int** area = malloc(sizeof(int*));
	for (int i=0;i<9;i++) {
		area[i]=malloc(sizeof(int));
	}
	/*On crée une liste des entiers que l'on va utiliser pour remplir les blocs diagonaux*/
	for (int k=0;k<2;k++){
		int processed[9];
		for (int x=0;x<2;x++){
			for (int y=0;y<2;y++){
				int n = rand()%8 +1;
				while (processed[n]==1){
					n=rand()%8 +1;
				}
				processed[n]=1;
				area[x+3*k][y+3*k] = n;
				printf("%d ",n);
			}
		printf("\n");
		}
	}
	return area;
}

int main(){
	int** grille = fill_grid();
};

	






