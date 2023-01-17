#include "food.h"



//bool food_flag;
//int food_x;


//генерируется случайное значение, которое используется в качестве координаты еды в поле игры
void generate_food(bool food_flag, int& food_x, int& food_y, const unsigned int* snake_x, const unsigned int* snake_y, int snake_size, int field_columns, int field_rows) {
	if (!food_flag) {
		/*food_x = (rand() % 2) ? ((3 < (MIN(snake_x[0], snake_x[snake_size - 1])))?(1 + rand() % (MIN(snake_x[0], snake_x[snake_size - 1]) - 2)):(MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])))) : (MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])));
		food_y = (rand() % 2) ? ((3 < (MIN(snake_y[0], snake_y[snake_size - 1]))) ? (1 + rand() % (MIN(snake_y[0], snake_y[snake_size - 1]) - 2)) : (MAX(snake_y[0], snake_y[snake_size - 1]) + rand() % (L - 1 - MAX(snake_y[0], snake_y[snake_size - 1])))) : (MAX(snake_y[0], snake_y[snake_size - 1]) + rand() % (L - 1 - MAX(snake_y[0], snake_y[snake_size - 1])));*/
		food_x = 1 + rand() % (field_columns - 2);
		food_y = 1 + rand() % (field_rows - 2);// 
		//checking for same coordinates with snake's ones
	}
}

void init_food(void) {

}



void init_food_struct(void) {

}
void generate_food_struct(FOOD& fd, const FIELD& field) {
	if (!fd.food_flag) {
		/*food_x = (rand() % 2) ? ((3 < (MIN(snake_x[0], snake_x[snake_size - 1])))?(1 + rand() % (MIN(snake_x[0], snake_x[snake_size - 1]) - 2)):(MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])))) : (MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])));
		food_y = (rand() % 2) ? ((3 < (MIN(snake_y[0], snake_y[snake_size - 1]))) ? (1 + rand() % (MIN(snake_y[0], snake_y[snake_size - 1]) - 2)) : (MAX(snake_y[0], snake_y[snake_size - 1]) + rand() % (L - 1 - MAX(snake_y[0], snake_y[snake_size - 1])))) : (MAX(snake_y[0], snake_y[snake_size - 1]) + rand() % (L - 1 - MAX(snake_y[0], snake_y[snake_size - 1])));*/
		fd.food_x = 1 + rand() % (field.columns - 2);
		fd.food_y = 1 + rand() % (field.rows - 2);// 
		//checking for same coordinates with snake's ones
	}
}
