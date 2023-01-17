#pragma once
#include "const.h"
//#include <conio.h>//
#include <windows.h>
#include <iostream>
#include "snake.h"

#define MAX(A, B)	((A)<(B)?(B):(A))
#define MIN(A, B)	((A)>(B)?(B):(A))
#define SIGN(A)	    ((A)<0?(-1):(1))

//extern bool food_flag;
//extern int food_x;

void init_food(void);
void generate_food(bool food_flag, int& food_x, int& food_y, const unsigned int* snake_x, const unsigned int* snake_y, int snake_size);
