#include "snake.h"
//current snake size
//int snake_size;// = 1;

////snake direction
//DIRECTION direction;// = DIRECTION::MOVE_RIGHT;
////Массив координат змейки по горизонтали(X)
//unsigned int snake_x[L];// = { 1 };

void init_snake(unsigned int* snake_x, unsigned int* snake_y, int snake_size, DIRECTION& direction, int  field_columns, int field_rows) {
	
    /*srand(time(0));*/
    snake_x[0] = 2 + rand() % (field_columns -2 - 2) ; //SIGN(snake_x[i-1]-L/2);
    snake_y[0] = 2 + rand() % (field_rows-2 - 2); //SIGN(snake_x[i-1]-L/2);
   
    for (int i = 1; i < snake_size; i++) {
        /*snake_x[i] = (i==0)?1+rand()%(L-2): snake_x[i-1]-1;*/
        if (i == 1) {
            snake_x[1] = (rand() % 2) ? snake_x[0] - SIGN(snake_x[0] - (field_columns -2) / 2) * 1 : snake_x[1] = snake_x[0]; //SIGN(snake_x[i-1]-L/2);
            snake_y[1] = (snake_x[1] == snake_x[0]) ? snake_y[0] - SIGN(snake_y[0] - (field_rows-2) / 2) * 1 : snake_y[1] = snake_y[0]; //SIGN(snake_x[i-1]-L/2);

        }
        else {
            snake_x[i] = (snake_y[i] == snake_y[i - 1]) ? snake_x[i - 1] - SIGN(snake_x[0] - (field_columns-2) / 2) * 1 : snake_x[i] = snake_x[i - 1]; //SIGN(snake_x[i-1]-L/2);
            snake_y[i] = (snake_x[i] == snake_x[i - 1]) ? snake_y[i - 1] - SIGN(snake_y[0] - (field_rows-2) / 2) * 1 : snake_y[i] = snake_y[i - 1]; //SIGN(snake_x[i-1]-L/2);
            //snake_x[i] = 1;
        }
    }

    if (snake_x[0] < L / 2) {
        direction = DIRECTION::MOVE_RIGHT;
    }
    else {
        direction = DIRECTION::MOVE_LEFT;
    }
}

void move_snake(unsigned int* snake_x, unsigned int* snake_y, int snake_size, const DIRECTION& direction, int  field_columns, int field_rows) {

    //двигаем змейку
  //положение змейки
  //
    static DIRECTION tmp_direction;
    if (snake_size > 1) {
        if ((tmp_direction == DIRECTION::MOVE_LEFT && direction == DIRECTION::MOVE_RIGHT) ||
            (tmp_direction == DIRECTION::MOVE_RIGHT && direction == DIRECTION::MOVE_LEFT) ||
            (tmp_direction == DIRECTION::MOVE_UP && direction == DIRECTION::MOVE_DOWN) ||
            (tmp_direction == DIRECTION::MOVE_DOWN && direction == DIRECTION::MOVE_UP)) {
            tmp_direction = tmp_direction;
        }
        else {
            tmp_direction = direction;
        }
    }
    else {
        tmp_direction = direction;
    }


    for (int i = snake_size - 1; i > 0; i--) {
        snake_x[i] = snake_x[i - 1];
        snake_y[i] = snake_y[i - 1];
        //if (snake_y[i] == snake_y[i - 1]) {
        //    snake_x[i] = snake_x[i - 1];
        //}
        //else {
        //    snake_y[i] = snake_y[i - 1];
        //}
    }

    if (tmp_direction == DIRECTION::MOVE_RIGHT) {
        //snake_x[0]++;
        //обнуляем, если значение достигло максимальноо элемента поля справа
        //snake_x[0] -= (columns - 2)*(snake_x[0]++/(columns - 2));
        if (snake_x[0] >= (field_columns - 2)) {
            snake_x[0] -= field_columns - 2;
        }
        snake_x[0]++;
    }

    if (tmp_direction == DIRECTION::MOVE_LEFT) {
        //snake_x[0]--;
        //присваиваем последний элемент справа, если значение достигло первого элемента поля
        //snake_x[0] += (columns - 2) * ((columns - 1-snake_x[0]--) / (columns - 2));
        if (snake_x[0] <= 1) {
            snake_x[0] += field_columns - 2;
        }
        snake_x[0]--;
    }
    if (tmp_direction == DIRECTION::MOVE_DOWN) {
        //snake_x[0]++;
        //обнуляем, если значение достигло максимальноо элемента поля справа
        //snake_x[0] -= (columns - 2)*(snake_x[0]++/(columns - 2));
        if (snake_y[0] >= (field_rows - 2)) {
            snake_y[0] -= field_rows - 2;
        }
        snake_y[0]++;
    }

    if (tmp_direction == DIRECTION::MOVE_UP) {
        //snake_x[0]--;
        //присваиваем последний элемент справа, если значение достигло первого элемента поля
        //snake_x[0] += (columns - 2) * ((columns - 1-snake_x[0]--) / (columns - 2));
        if (snake_y[0] <= 1) {
            snake_y[0] += field_rows - 2;
        }
        snake_y[0]--;
    }

}

void grow_snake(bool food_flag, int & snake_size) {
    if (!food_flag) {
        snake_size++;
    }
}

//for struct

void init_snake_struct(SNAKE& mysnake, const FIELD& field) {
    /*srand(time(0));*/
    mysnake.snake_x[0] = 2 + rand() % (field.columns - 2 - 2); //SIGN(snake_x[i-1]-L/2);
    mysnake.snake_y[0] = 2 + rand() % (field.rows - 2 - 2); //SIGN(snake_x[i-1]-L/2);

    for (int i = 1; i < mysnake.snake_size; i++) {
        /*snake_x[i] = (i==0)?1+rand()%(L-2): snake_x[i-1]-1;*/
        if (i == 1) {
            mysnake.snake_x[1] = (rand() % 2) ? mysnake.snake_x[0] - SIGN(mysnake.snake_x[0] - (field.columns - 2) / 2) * 1 : mysnake.snake_x[1] = mysnake.snake_x[0]; //SIGN(snake_x[i-1]-L/2);
            mysnake.snake_y[1] = (mysnake.snake_x[1] == mysnake.snake_x[0]) ? mysnake.snake_y[0] - SIGN(mysnake.snake_y[0] - (field.rows - 2) / 2) * 1 : mysnake.snake_y[1] = mysnake.snake_y[0]; //SIGN(snake_x[i-1]-L/2);

        }
        else {
            mysnake.snake_x[i] = (mysnake.snake_y[i] == mysnake.snake_y[i - 1]) ? mysnake.snake_x[i - 1] - SIGN(mysnake.snake_x[0] - (field.columns - 2) / 2) * 1 : mysnake.snake_x[i] = mysnake.snake_x[i - 1]; //SIGN(snake_x[i-1]-L/2);
            mysnake.snake_y[i] = (mysnake.snake_x[i] == mysnake.snake_x[i - 1]) ? mysnake.snake_y[i - 1] - SIGN(mysnake.snake_y[0] - (field.rows - 2) / 2) * 1 : mysnake.snake_y[i] = mysnake.snake_y[i - 1]; //SIGN(snake_x[i-1]-L/2);
            //snake_x[i] = 1;
        }
    }

    if (mysnake.snake_x[0] < field.columns / 2) {
        mysnake.direction = DIRECTION::MOVE_RIGHT;
    }
    else {
        mysnake.direction = DIRECTION::MOVE_LEFT;
    }
}
void move_snake_struct(SNAKE& mysnake, const FIELD& field) {
    //двигаем змейку
//положение змейки
//
    static DIRECTION tmp_direction;
    if (mysnake.snake_size > 1) {
        if ((tmp_direction == DIRECTION::MOVE_LEFT && mysnake.direction == DIRECTION::MOVE_RIGHT) ||
            (tmp_direction == DIRECTION::MOVE_RIGHT && mysnake.direction == DIRECTION::MOVE_LEFT) ||
            (tmp_direction == DIRECTION::MOVE_UP && mysnake.direction == DIRECTION::MOVE_DOWN) ||
            (tmp_direction == DIRECTION::MOVE_DOWN && mysnake.direction == DIRECTION::MOVE_UP)) {
            tmp_direction = tmp_direction;
        }
        else {
            tmp_direction = mysnake.direction;
        }
    }
    else {
        tmp_direction = mysnake.direction;
    }


    for (int i = mysnake.snake_size - 1; i > 0; i--) {
        mysnake.snake_x[i] = mysnake.snake_x[i - 1];
        mysnake.snake_y[i] = mysnake.snake_y[i - 1];
        //if (snake_y[i] == snake_y[i - 1]) {
        //    snake_x[i] = snake_x[i - 1];
        //}
        //else {
        //    snake_y[i] = snake_y[i - 1];
        //}
    }

    if (tmp_direction == DIRECTION::MOVE_RIGHT) {
        //snake_x[0]++;
        //обнуляем, если значение достигло максимальноо элемента поля справа
        //snake_x[0] -= (columns - 2)*(snake_x[0]++/(columns - 2));
        if (mysnake.snake_x[0] >= (field.columns - 2)) {
            mysnake.snake_x[0] -= field.columns - 2;
        }
        mysnake.snake_x[0]++;
    }
    if (tmp_direction == DIRECTION::MOVE_LEFT) {
        //snake_x[0]--;
        //присваиваем последний элемент справа, если значение достигло первого элемента поля
        //snake_x[0] += (columns - 2) * ((columns - 1-snake_x[0]--) / (columns - 2));
        if (mysnake.snake_x[0] <= 1) {
            mysnake.snake_x[0] += field.columns - 2;
        }
        mysnake.snake_x[0]--;
    }
    if (tmp_direction == DIRECTION::MOVE_DOWN) {
        //snake_x[0]++;
        //обнуляем, если значение достигло максимальноо элемента поля справа
        //snake_x[0] -= (columns - 2)*(snake_x[0]++/(columns - 2));
        if (mysnake.snake_y[0] >= (field.rows - 2)) {
            mysnake.snake_y[0] -= field.rows - 2;
        }
        mysnake.snake_y[0]++;
    }

    if (tmp_direction == DIRECTION::MOVE_UP) {
        //snake_x[0]--;
        //присваиваем последний элемент справа, если значение достигло первого элемента поля
        //snake_x[0] += (columns - 2) * ((columns - 1-snake_x[0]--) / (columns - 2));
        if (mysnake.snake_y[0] <= 1) {
            mysnake.snake_y[0] += field.rows - 2;
        }
        mysnake.snake_y[0]--;
    }
}


void grow_snake_struct(const FOOD& fd, SNAKE& mysnake) {
    if (!fd.food_flag) {
        mysnake.snake_size++;
    }
}