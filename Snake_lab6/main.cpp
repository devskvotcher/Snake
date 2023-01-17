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

#define AUTOMATIC 

int main()
{
    //������
    //current snake size
    int snake_size_m;
    //������� ����������� ����
    bool game_on_m;
    //delay timeout
    unsigned int timeout_m;
    bool food_flag_m;
    int food_x_m;
    char field_m[columns];
    //snake direction
    DIRECTION direction_m;// = DIRECTION::MOVE_RIGHT;
    //������ ��������� ������ �� �����������(X)
    unsigned int snake_x_m[L];// = { 1 };


    init_game(timeout_m,snake_size_m,game_on_m,food_flag_m);

    init_snake(snake_x_m, snake_size_m, direction_m);

    generate_food(food_flag_m, food_x_m, snake_x_m, snake_size_m);

    init_field(field_m);
    
    set_food(field_m, food_x_m);

    set_snake(field_m, snake_x_m, snake_size_m);

    print_field(field_m);
    
        //����� �� ����� ���������
        std::cout << "For beginning press any key";

    keyboard_scan(direction_m, game_on_m);

    while (game_on_m) {

            //system("cls");//!!!!!!!!!!
            setCursorPosition(0, 0);

            check_eating(snake_x_m, food_flag_m, food_x_m);
            
            generate_food(food_flag_m, food_x_m, snake_x_m, snake_size_m);

            grow_snake(food_flag_m, snake_size_m);

            move_snake(snake_x_m, snake_size_m, direction_m);

            check_game(snake_size_m, game_on_m);

            check_snake(snake_x_m, game_on_m);

            clear_field(field_m);

            set_food(field_m, food_x_m);

            set_snake(field_m,snake_x_m, snake_size_m);
                
            print_field(field_m);
               
                //����� �� ����� ���������
                std::cout << "QUIT: ESC\tLEFT: <\tRIGHT: >\tUP: ^\tDOWN: v\n";

#ifdef AUTOMATIC       
            if (_kbhit())
#endif
            {
                keyboard_scan(direction_m, game_on_m);

            }
            Sleep(timeout_m);

    }

}
