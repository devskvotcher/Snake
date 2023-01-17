#pragma once
#include <iostream>
//connect getch()
#include <conio.h>
#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"

using std::cout;
using std::cin;
using std::endl;
//������� ����������� ����
//extern bool game_on;

//delay timeout
//extern unsigned int timeout;

void init_game(unsigned int& timeout, int& snake_size, int& field_columns, int& field_rows, bool& game_on, bool& food_flag);
void set_snake(char **field, int field_columns, int field_rows, const unsigned int* snake_x, const unsigned int* snake_y, int snake_size);
void set_food(char **field, int food_x, int food_y);
void check_snake(const unsigned int* snake_x, const unsigned int* snake_y, int snake_size, bool& game_on, int field_columns, int field_rows);
void check_game(int snake_size, bool& game_on);
void check_eating(const unsigned int* snake_x, const unsigned int* snake_y, bool& food_flag, int food_x, int food_y);
void clear_snake(char** field, int* snake_x, int snake_size);

void keyboard_scan(DIRECTION& direction, bool& game_on);
