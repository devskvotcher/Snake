#pragma once
#include <iostream>
//connect getch()
#include <conio.h>
#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"
//Признак продолжения игры
extern bool game_on;

//delay timeout
extern unsigned int timeout;

void init_game(void);
void set_snake(void);
void set_food(void);
void check_snake(void);
void check_game(void);
void check_eating(void);
void clear_snake(void);

void keyboard_scan(void);
