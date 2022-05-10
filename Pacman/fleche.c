#include <ncurses.h> //EDIT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"

void arrows(struct pacman * PACMAN){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    timeout(0); //EDIT
    int c; //EDIT
    int i = 0;
    while(i <=1)
    {
        c = getch();
        if(c!=ERR)
        {
            switch(c)
            {
                case KEY_UP:
                    printw("Appui de la fleche du haut\n");
                    PACMAN->ny = 1;
                    i+=1;
                    break;
                case KEY_DOWN:
                    printw("Appui de la fleche du bas\n");
                    PACMAN->ny = -1;
                    i+=1;
                    break;
                case KEY_LEFT:
                    printw("Appui de la fleche de gauche\n");
                    PACMAN->nx = -1;
                    i+=1;
                    break;
                case KEY_RIGHT:
                    printw("Appui de la fleche de droite\n");
                    PACMAN->nx = 1;
                    i+=1;
                    break;
            }
        }
        refresh();
    }
    endwin(); //EDIT


}
int main(){

  arrows();
  return 0;
}
