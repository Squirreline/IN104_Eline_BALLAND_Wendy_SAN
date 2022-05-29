#ifndef __CHECK_H__
#define __CHECK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define dim (9)

bool check_line(int**, int , int );
bool check_column(int** , int , int );
bool check_square(int** , int , int , int );
bool is_allowed(int** , int , int , int );
#endif
