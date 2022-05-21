#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "check.h"
#include "erase.h"
#include "construction.h"
#include "play.h"

#define dim (9)

int main(){
	int** area = fill_grid();
	//display(area);
	int difficulty;
    printf("Choisissez votre difficulté : facile (1), intermédiaire (2), difficile (3)\n");
    int n_values=0;
    while (n_values==0){

      scanf("%d",&difficulty);

      if (difficulty==1){
        
        n_values = 71;}
      else if (difficulty==2){ n_values = 73;}
      else if (difficulty==3){ n_values = 75;}
      else { printf("Format de difficulté incorrect, merci de préciser.\n");}
    }
	int** grid = erase_values(area,n_values);
	display(grid);
	play(n_values);
};
