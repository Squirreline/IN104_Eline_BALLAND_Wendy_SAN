#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dim (9)

int** fill_grid();
bool check_line(int** , int , int );
bool check_column(int** , int , int );
bool check_square(int** , int x, int y, int );
