#pragma once
#include "const.h"
//#include <conio.h>//
#include <windows.h>
#include <iostream>
#include "snake.h"
#include "field.h"

#define MAX(A, B)	((A)<(B)?(B):(A))
#define MIN(A, B)	((A)>(B)?(B):(A))
#define SIGN(A)	    ((A)<0?(-1):(1))

struct FOOD {
    int food_x;
    int food_y;
    bool food_flag;
};

//extern bool food_flag;
//extern int food_x;

void init_food(void);
void generate_food(bool food_flag, int& food_x, int& food_y, const unsigned int* snake_x, const unsigned int* snake_y, int snake_size, int field_columns, int field_rows);


void init_food_struct(void);
void generate_food_struct(FOOD& fd, const FIELD& field);
