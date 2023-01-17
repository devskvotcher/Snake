#include "snake.h"
//current snake size
int snake_size;// = 1;

//snake direction
DIRECTION direction;// = DIRECTION::MOVE_RIGHT;
//Массив координат змейки по горизонтали(X)
unsigned int snake_x[L];// = { 1 };

void init_snake(void) {
	
    /*srand(time(0));*/
    for (int i = 0; i < snake_size; i++) {
        /*snake_x[i] = (i==0)?1+rand()%(L-2): snake_x[i-1]-1;*/
        snake_x[i] = (i == 0) ? 2 + rand() % (L - 2) : snake_x[i- 1] - SIGN(snake_x[0] - L / 2) * 1; //SIGN(snake_x[i-1]-L/2);
        //snake_x[i] = 1;
    }

    if (snake_x[0] < L / 2) {
        direction = DIRECTION::MOVE_RIGHT;
    }
    else {
        direction = DIRECTION::MOVE_LEFT;
    }
}

void move_snake(void) {

    //двигаем змейку
  //положение змейки
  //
    for (int i = snake_size - 1; i > 0; i--) {

        snake_x[i] = snake_x[i - 1];
    }
    if (direction == DIRECTION::MOVE_RIGHT) {
        snake_x[0]++;
    }
    if (direction == DIRECTION::MOVE_LEFT) {

        snake_x[0]--;
    }
}

void grow_snake(void) {
    if (!food_flag) {
        snake_size++;
    }
}

