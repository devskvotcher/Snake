#pragma once

#include <iostream>
#include "const.h"
#include "field.h"
#include "food.h"

#define MAX(A, B)	((A)<(B)?(B):(A))
#define MIN(A, B)	((A)>(B)?(B):(A))
#define SIGN(A)	    ((A)<0?(-1):(1))

struct FOOD;//!!!!!!!!!!!!!!!!!!!!!!!!

struct SNAKE {
    
    //current snake size
    int snake_size;
    //snake direction
    DIRECTION direction;// = DIRECTION::MOVE_RIGHT;
    //Массив координат змейки по горизонтали(X)
    unsigned int snake_x[L * H];// = { 1 };
     //Массив координат змейки по вертикали(Y)
    unsigned int snake_y[H * L];// = { 1 };
};




//snake size
//extern int snake_size;

//snake direction
//extern DIRECTION direction;
//Массив координат змейки по горизонтали(X)
//extern unsigned int snake_x[];

void init_snake(unsigned int* snake_x, unsigned int* snake_y, int snake_size, DIRECTION& direction, int  field_columns, int field_rows);
void move_snake(unsigned int* snake_x, unsigned int* snake_y, int snake_size, const DIRECTION& direction, int  field_columns, int field_rows);
void grow_snake(bool food_flag, int& snake_size);

void init_snake_struct(SNAKE & mysnake, const FIELD& myfield);
void move_snake_struct(SNAKE& mysnake, const FIELD& myfield);

void grow_snake_struct(const FOOD& fd, SNAKE& mysnake);
