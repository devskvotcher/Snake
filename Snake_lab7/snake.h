#pragma once
#include "const.h"
#include "food.h"
#include <iostream>

#define MAX(A, B)	((A)<(B)?(B):(A))
#define MIN(A, B)	((A)>(B)?(B):(A))
#define SIGN(A)	    ((A)<0?(-1):(1))

//snake size
//extern int snake_size;

//snake direction
//extern DIRECTION direction;
//Массив координат змейки по горизонтали(X)
//extern unsigned int snake_x[];

void init_snake(unsigned int* snake_x, unsigned int* snake_y, int snake_size,DIRECTION& direction);
void move_snake(unsigned int* snake_x, unsigned int* snake_y, int snake_size, const DIRECTION& direction);
void grow_snake(bool food_flag, int& snake_size);
