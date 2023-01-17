#include "game.h"
////Признак продолжения игры
//bool game_on;
////delay timeout
//unsigned int timeout ;
//Устанавливаются начальные значения параметров игры
void init_game(unsigned int& timeout,int& snake_size, bool& game_on, bool& food_flag) {
    srand(time(0));
	timeout = 500;
    snake_size = 5;
    game_on = false;// true;
    food_flag=false;
}
//Змейка устанавливается в игровом поле
void set_snake(char (*field)[rows], const unsigned int* snake_x, const unsigned int* snake_y, int snake_size) {

    //размещаем змейку
    //for(int j=0; j < snake_size; j++)
    {
        for (int i = 0; i < snake_size; i++) {
            //if (snake_x[i] != 0){
            if ((snake_x[i] != 0 && snake_x[i]!= (columns-1))&&(snake_y[i] != 0 && snake_y[i] != (rows - 1))) {
                if (i == 0 /*&& j==0*/) {
                    //положение головы
                    field[snake_x[i]][snake_y[i]] = head_symbol;
                }
                else {
                    field[snake_x[i]][snake_y[i]] = tail_symbol;
                }
            }
        }
    }
}
//Еда устанавливается в игровом поле
void set_food(char (*field)[rows], int food_x, int food_y) {

    field[food_x][food_y] = food_symbol;
}
//Выполняется проверка того,что на поле есть свободное место для передвижения
void check_game(int snake_size, bool& game_on) {
    if (game_on) {
        if (snake_size >= L) {
            game_on = false;
        }
        else {
            game_on = true;
        }
    }
}
//Выполняется проверка того,что змейка встретилась с границей поля
void check_snake(const unsigned int* snake_x, const unsigned int* snake_y, int snake_size, bool& game_on) {
    if (game_on) {
        if (snake_x[0] > 0 && snake_x[0] < columns - 1 ) {
            game_on = true;
        }
        else {
            game_on = false;
        }
        if (snake_y[0] > 0 && snake_y[0] < rows - 1) {
            game_on = true;
        }
        else {
            game_on = false;
        }

        //check biting tail
        for (int i = 1; i < snake_size; i++) {
            if ((snake_x[0] == snake_x[i]) && (snake_y[0] == snake_y[i])) {
                game_on = false;
                break;
            }
            else {
                game_on = true;
            }
        }
    }
}
//Выполняется проверка того, что змейка съела еду
void check_eating(const unsigned int* snake_x, const unsigned int* snake_y, bool& food_flag, int food_x, int food_y) {
   /* if (game_on) {*/
        if (snake_x[0] == food_x && snake_y[0] == food_y) {
            food_flag = false;
        }
        else {
            food_flag = true;
        //}
    }
}
//Очищается позиция змейки в массиве
void clear_snake(char (*field)[rows], int* snake_x, int* snake_y, int snake_size) {

    //очищаем позиции змейки
    for (int j = 0; j < snake_size; j++) {
        for (int i = 0; i < snake_size; i++) {
            field[snake_x[i]][snake_y[j]] = ' ';
        }
    }
}

void keyboard_scan(DIRECTION& direction, bool& game_on) {
    //обработка нажатий клавиш
    
        unsigned char direction1 = 0, direction2 = 0;

        direction1 = _getch();/////////////////////////вот они     //_getch(); и  //system("PAUSE");

        if (KEYS::ESC == direction1) {
            game_on = false;
            return;
        }
        else
            game_on = true;
        {
            if (224 == direction1)
            {
                direction2 = _getch();
                switch (direction2) {
                    //left
                case KEYS::LEFT/*75*/:
                    //std::cout << '@' << "left" << std::endl;
                    direction = DIRECTION::MOVE_LEFT;
                    game_on = true;
                    break;
                    //right
                case KEYS::RIGHT/*77*/:
                    //std::cout << '@' << "right" << std::endl;
                    direction = DIRECTION::MOVE_RIGHT;
                    game_on = true;
                    break;
                    //up
                case KEYS::UP://72:
                    //std::cout << '@' << "up" << std::endl;
                    direction = DIRECTION::MOVE_UP;
                    game_on = true;
                    break;
                    //down
                case KEYS::DOWN://80:
                    //std::cout << '@' << "down" << std::endl;
                    direction = DIRECTION::MOVE_DOWN;
                    game_on = true;
                    break;
                    //exit
                case KEYS::ESC://27:
                    //std::cout << '@' << "ESC" << std::endl;
                    game_on = false;
                    break;
                default:
                    //std::cout << '@' << "def" << std::endl;
                    game_on = true;
                }
            }
        }
    
}
