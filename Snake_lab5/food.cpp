#include "food.h"



bool food_flag;
int food_x;


//генерируется случайное значение, которое используется в качестве координаты еды в поле игры
void generate_food(void) {
	if (!food_flag) {
		//srand(time(0));
		//int a1;
		food_x = (rand() % 2) ? ((3 < (MIN(snake_x[0], snake_x[snake_size - 1])))?(1 + rand() % (MIN(snake_x[0], snake_x[snake_size - 1]) - 2)):(MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])))) : (MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])));
		/*if (rand() % 2) {*/
			////int t = (MIN(snake_x[0], snake_x[snake_size - 1]) - 2);
			////bool tt = 3 < (MIN(snake_x[0], snake_x[snake_size - 1]));//bool tt = 1 < (int)(MIN(snake_x[0], snake_x[snake_size - 1]-2));!!!!!!!!!!!!!!
			//if (3 < (MIN(snake_x[0], snake_x[snake_size - 1]))) {


			//	a1 = (1 + rand() % (MIN(snake_x[0], snake_x[snake_size - 1]) - 2));
			//}
			//else {
			//	a1 = (MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])));
			//}
		/*}
		else {
			a1=(MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])));
		}*/
		//food_x = a1;
	}
}
