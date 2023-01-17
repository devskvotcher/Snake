// snake5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//using std::cout;
//using std::endl;
////connect getch()
//#include <conio.h>
//#include <windows.h>
#include "snake.h"
#include "game.h"
#include "field.h"
#include "food.h"

//#define MAX(A, B)	((A)<(B)?(B):(A))
//#define MIN(A, B)	((A)>(B)?(B):(A))
//#define SIGN(A)	    ((A)<0?(-1):(1))

#define AUTOMATIC 

int main()
{
    init_game();

    init_snake();

    generate_food();

    init_field();
    
    set_food();

    set_snake();

    print_field();
    
        //вывод на экран подсказок
        std::cout << "For beginning press any key";

    keyboard_scan();

    while (game_on) {

            system("cls");//!!!!!!!!!!

            check_eating();
            
            generate_food();

            grow_snake();

            move_snake();

            check_game();

            check_snake();

            clear_field();

            set_food();

            set_snake();
                
            print_field();
               
                //вывод на экран подсказок
                std::cout << "QUIT: ESC\tLEFT: <\tRIGHT: >\tUP: ^\tDOWN: v\n";

#ifdef AUTOMATIC       
            if (_kbhit())
#endif
            {
                keyboard_scan();

            }
            Sleep(timeout);

    }

}
