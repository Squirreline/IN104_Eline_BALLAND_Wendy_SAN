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
	srand(time(NULL));
	int** area = malloc(sizeof(int*)*9);
	for (int i=0;i<9;i++) {
		area[i]=malloc(sizeof(int)*9);
	}
	/*On remplit les blocs diagonaux, indépendants entre eux*/
	int processed[9];
	for (int k=0;k<=2;k++){
	/*On initialise le tableau des nombres traités*/
		for (int i=0;i<9;i++){
			processed[i]=0;
		}
		int c =0;
		for (int x=0;x<=2;x++){
			for (int y=0;y<=2;y++){
				int n = rand()%9 +1;
				while ((processed[n-1]==1)&&(c!=9)){
					n=rand()%9 +1;
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
	/*printf("%d",area[8][8]);
	for (int i=0;i<=2;i++){
		for (int j=0;j<=2;j++){
			if (i!=j){
			/*On initialise le tableau des nombres traités
				for (int i=0;i<9;i++){
					processed[i]=0;
				}
			}
			int n = rand()%9 +1;*/
			
			
	/*On remplit les blocs restant*/
	//???????????????????????//
	return area;
}



int main(){
	int** grille = fill_grid();
};

	






