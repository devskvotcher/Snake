#include "food.h"



//bool food_flag;
//int food_x;


//генерируется случайное значение, которое используется в качестве координаты еды в поле игры
void generate_food(bool food_flag, int& food_x, const unsigned int* snake_x, int snake_size) {
	if (!food_flag) {
		food_x = (rand() % 2) ? ((3 < (MIN(snake_x[0], snake_x[snake_size - 1])))?(1 + rand() % (MIN(snake_x[0], snake_x[snake_size - 1]) - 2)):(MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])))) : (MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])));
	}
}

void init_food(void) {

}
