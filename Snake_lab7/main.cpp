// snake6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//using std::cout;
//using std::endl;
////connect getch()
//#include <conio.h>
//#include <windows.h>
#include "winconsole.h"

#include "snake.h"
#include "game.h"
#include "field.h"
#include "food.h"

//#define AUTOMATIC 

int main()
{
    //данные
    //current snake size
    int snake_size_m;
    //Признак продолжения игры
    bool game_on_m;
    //delay timeout
    unsigned int timeout_m;
    bool food_flag_m;
    int food_x_m;
    int food_y_m;
    char field_m[columns][rows];
    //snake direction
    DIRECTION direction_m;// = DIRECTION::MOVE_RIGHT;
    //Массив координат змейки по горизонтали(X)
    unsigned int snake_x_m[L*H];// = { 1 };
     //Массив координат змейки по вертикали(Y)
    unsigned int snake_y_m[H*L];// = { 1 };


    init_game(timeout_m,snake_size_m,game_on_m,food_flag_m);

    init_snake(snake_x_m, snake_y_m, snake_size_m, direction_m);

    generate_food(food_flag_m, food_x_m, food_y_m, snake_x_m, snake_y_m, snake_size_m);

    init_field(field_m);
    
    //set_food(field_m, food_x_m);

    //set_snake(field_m, snake_x_m, snake_size_m);

    print_field(field_m);
    
        //вывод на экран подсказок
        std::cout << "For beginning press any key";

    keyboard_scan(direction_m, game_on_m);

    while (game_on_m) {

#ifdef AUTOMATIC       
        if (_kbhit())
#endif
        {
            keyboard_scan(direction_m, game_on_m);

        }
            //system("cls");//!!!!!!!!!!
            setCursorPosition(0, 0);

            check_eating(snake_x_m, snake_y_m, food_flag_m, food_x_m, food_y_m);
            
            generate_food(food_flag_m, food_x_m, food_y_m, snake_x_m, snake_y_m, snake_size_m);

            grow_snake(food_flag_m, snake_size_m);

            move_snake(snake_x_m, snake_y_m, snake_size_m, direction_m);

            check_game(snake_size_m, game_on_m);

            check_snake(snake_x_m, snake_y_m, snake_size_m, game_on_m);

            clear_field(field_m);

            set_food(field_m, food_x_m,food_y_m);

            set_snake(field_m,snake_x_m, snake_y_m, snake_size_m);
                
            print_field(field_m);
               
                //вывод на экран подсказок
                std::cout << "QUIT: ESC\tLEFT: <\tRIGHT: >\tUP: ^\tDOWN: v\n";
#ifdef _DEBUG
                std::cout <<"DEBUG info: direction is " << direction_m << '\n';
#endif

            Sleep(timeout_m);

    }

}
