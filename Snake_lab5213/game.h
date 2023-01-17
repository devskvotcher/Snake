#pragma once
int timeout=300;
bool game_on=false;
extern char snake[];
extern char field[];
extern const int COLUMNS;
extern const char field_symbol;
extern unsigned int snake_size;
extern int snake_x[];
extern const char HEAD_SYMBOL;
extern const char TAIL_SYMBOL;
void init_game();
void set_snake();


