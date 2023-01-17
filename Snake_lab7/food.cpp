#include "food.h"



//bool food_flag;
//int food_x;


//генерируется случайное значение, которое используется в качестве координаты еды в поле игры
void generate_food(bool food_flag, int& food_x, int& food_y, const unsigned int* snake_x, const unsigned int* snake_y, int snake_size) {
	if (!food_flag) {
		/*food_x = (rand() % 2) ? ((3 < (MIN(snake_x[0], snake_x[snake_size - 1])))?(1 + rand() % (MIN(snake_x[0], snake_x[snake_size - 1]) - 2)):(MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])))) : (MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])));
		food_y = (rand() % 2) ? ((3 < (MIN(snake_y[0], snake_y[snake_size - 1]))) ? (1 + rand() % (MIN(snake_y[0], snake_y[snake_size - 1]) - 2)) : (MAX(snake_y[0], snake_y[snake_size - 1]) + rand() % (L - 1 - MAX(snake_y[0], snake_y[snake_size - 1])))) : (MAX(snake_y[0], snake_y[snake_size - 1]) + rand() % (L - 1 - MAX(snake_y[0], snake_y[snake_size - 1])));*/
		food_x = 1 + rand() % (columns - 2);
		food_y = 1 + rand() % (rows - 2);// 
		//checking for same coordinates with snake's ones
	}
}

void init_food(void) {

}
