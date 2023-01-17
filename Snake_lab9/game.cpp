#include "game.h"
////Признак продолжения игры
//bool game_on;
////delay timeout
//unsigned int timeout ;
//Устанавливаются начальные значения параметров игры
void init_game(unsigned int& timeout,int& snake_size, int& field_columns, int& field_rows, bool& game_on, bool& food_flag) {
    srand(time(0));
	timeout = 500;
    snake_size = 5;
    game_on = false;// true;
    food_flag=false;

    std::cout << "Vvedite kolichestvo strok:";
    std::cin >> field_rows;
    std::cout << std::endl;
    std::cout << "Vvedite kolichestvo stolbtsov:";
    std::cin >> field_columns;
    std::cout << std::endl;

}
//Змейка устанавливается в игровом поле
void set_snake(char **field, int field_columns, int field_rows, const unsigned int* snake_x, const unsigned int* snake_y, int snake_size) {

    //размещаем змейку
    //for(int j=0; j < snake_size; j++)
    {
        for (int i = 0; i < snake_size; i++) {
            //if (snake_x[i] != 0){
            if ((snake_x[i] != 0 && snake_x[i]!= (field_columns -1))&&(snake_y[i] != 0 && snake_y[i] != (field_rows - 1))) {
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
void set_food(char **field, int food_x, int food_y) {

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
void check_snake(const unsigned int* snake_x, const unsigned int* snake_y, int snake_size, bool& game_on, int field_columns, int field_rows) {
    if (game_on) {
        if (snake_x[0] > 0 && snake_x[0] < field_columns - 1 ) {
            game_on = true;
        }
        else {
            game_on = false;
        }
        if (snake_y[0] > 0 && snake_y[0] < field_rows - 1) {
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
void clear_snake(char **field, int* snake_x, int* snake_y, int snake_size) {

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


void init_game_struct(GAME& mygame, SNAKE& mysnake,FIELD& field, FOOD& food) {
    srand(time(0));
    //mygame.timeout = 500;
    //mysnake.snake_size = 5;
    mygame.game_on = false;// true;
    food.food_flag = false;

    std::cout << "Vvedite kolichestvo strok:";
    std::cin >> field.rows;
    std::cout << std::endl;
    std::cout << "Vvedite kolichestvo stolbtsov:";
    std::cin >> field.columns;
    std::cout << std::endl;

    std::cout << "Vvedite razmer zmeiki:";
    std::cin >> mysnake.snake_size;
    std::cout << std::endl;
    std::cout << "Vvedite timeoyt (ms):";
    std::cin >> mygame.timeout;
    std::cout << std::endl;
}
void set_snake_struct(FIELD& field, const SNAKE& snake) {
    //размещаем змейку
//for(int j=0; j < snake_size; j++)
    {
        for (int i = 0; i < snake.snake_size; i++) {
            //if (snake_x[i] != 0){
            if ((snake.snake_x[i] != 0 && snake.snake_x[i] != (field.columns - 1)) && (snake.snake_y[i] != 0 && snake.snake_y[i] != (field.rows - 1))) {
                if (i == 0 /*&& j==0*/) {
                    //положение головы
                    field.field[snake.snake_x[i]][snake.snake_y[i]] = head_symbol;
                }
                else {
                    field.field[snake.snake_x[i]][snake.snake_y[i]] = tail_symbol;
                }
            }
        }
    }
}
void set_food_struct(FIELD& field, FOOD& food) {
    field.field[food.food_x][food.food_y] = food_symbol;
}
void check_snake_struct(const SNAKE& snake, GAME& mygame, const FIELD& field) {
    if (mygame.game_on) {
        if (snake.snake_size >= field.columns*field.rows) {
            mygame.game_on = false;
        }
        else {
            mygame.game_on = true;
        }
    }
}
void check_game_struct(const SNAKE& snake, GAME& mygame,const FIELD& field) {
    if (mygame.game_on) {
        if (snake.snake_x[0] > 0 && snake.snake_x[0] < field.columns - 1) {
            mygame.game_on = true;
        }
        else {
            mygame.game_on = false;
        }
        if (snake.snake_y[0] > 0 && snake.snake_y[0] < field.rows - 1) {
            mygame.game_on = true;
        }
        else {
            mygame.game_on = false;
        }

        //check biting tail
        for (int i = 1; i < snake.snake_size; i++) {
            if ((snake.snake_x[0] == snake.snake_x[i]) && (snake.snake_y[0] == snake.snake_y[i])) {
                mygame.game_on = false;
                break;
            }
            else {
                mygame.game_on = true;
            }
        }
    }
}
void check_eating_struct(const SNAKE& snake, FOOD& food) {

    if (snake.snake_x[0] == food.food_x && snake.snake_y[0] == food.food_y) {
        food.food_flag = false;
    }
    else {
        food.food_flag = true;
 
    }
}
void clear_snake_struct(FIELD& field, SNAKE& snake) {
    //очищаем позиции змейки
    for (int j = 0; j < snake.snake_size; j++) {
        for (int i = 0; i < snake.snake_size; i++) {
            field.field[snake.snake_x[i]][snake.snake_y[j]] = ' ';
        }
    }
}

void keyboard_scan_struct(SNAKE& snake, GAME& game) {
    //обработка нажатий клавиш

    unsigned char direction1 = 0, direction2 = 0;

    direction1 = _getch();/////////////////////////вот они     //_getch(); и  //system("PAUSE");

    if (KEYS::ESC == direction1) {
        game.game_on = false;
        return;
    }
    else
        game.game_on = true;
    {
        if (224 == direction1)
        {
            direction2 = _getch();
            switch (direction2) {
                //left
            case KEYS::LEFT/*75*/:
                //std::cout << '@' << "left" << std::endl;
                snake.direction = DIRECTION::MOVE_LEFT;
                game.game_on = true;
                break;
                //right
            case KEYS::RIGHT/*77*/:
                //std::cout << '@' << "right" << std::endl;
                snake.direction = DIRECTION::MOVE_RIGHT;
                game.game_on = true;
                break;
                //up
            case KEYS::UP://72:
                //std::cout << '@' << "up" << std::endl;
                snake.direction = DIRECTION::MOVE_UP;
                game.game_on = true;
                break;
                //down
            case KEYS::DOWN://80:
                //std::cout << '@' << "down" << std::endl;
                snake.direction = DIRECTION::MOVE_DOWN;
                game.game_on = true;
                break;
                //exit
            case KEYS::ESC://27:
                //std::cout << '@' << "ESC" << std::endl;
                game.game_on = false;
                break;
            default:
                //std::cout << '@' << "def" << std::endl;
                game.game_on = true;
            }
        }
    }
}
