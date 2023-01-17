#pragma once
#include "const.h"
#include "food.h"
#include <iostream>

#define MAX(A, B)	((A)<(B)?(B):(A))
#define MIN(A, B)	((A)>(B)?(B):(A))
#define SIGN(A)	    ((A)<0?(-1):(1))

//snake size
extern int snake_size;

//snake direction
extern DIRECTION direction;
//������ ��������� ������ �� �����������(X)
extern unsigned int snake_x[];

void init_snake(void);
void move_snake(void);
void grow_snake(void);
