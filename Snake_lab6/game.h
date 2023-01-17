#pragma once
#include <iostream>
//connect getch()
#include <conio.h>
#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"
//Признак продолжения игры
//extern bool game_on;

//delay timeout
//extern unsigned int timeout;

void init_game(unsigned int& timeout, int& snake_size, bool& game_on, bool& food_flag);
void set_snake(char* field, const unsigned int* snake_x, int snake_size);
void set_food(char* field, int food_x);
void check_snake(unsigned int* snake_x, bool& game_on);
void check_game(int snake_size, bool& game_on);
void check_eating(unsigned int* snake_x, bool& food_flag, int food_x);
void clear_snake(char* field, int* snake_x, int snake_size);

void keyboard_scan(DIRECTION& direction, bool& game_on);
