#include <iostream>
#include <conio.h>
#include "game.h"
//#include "game.cpp"
#include "field.h"
#include "snake.h"
#include "const.h"
#include "food.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#define AUTOMATIC
void print(char* field, const int SIZE)
{
    srand(time(NULL));
    system("cls");
    field[0] = border_symbol;
    field[COLUMNS - 1] = border_symbol;
    std::cout << "\n";
    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << "*";
    }
    std::cout << "\n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << field[i];
    }
    std::cout << "\n";
    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << "*";
    }
    std::cout << "\n";
}

int main()
{
    setlocale(0, "Rus");
    init_game();
//    //Очистка всего игрового поля
//    system("cls");
//    //Подготовка игрового поля
//    for (int i = 1; i < COLUMNS - 1; i++)
//    {
//        field[i] = field_symbol;
//    }
//    //Создаем змейку 
//    for (int i = 0; i < snake_size; i++)
//    {
//        if (i == 0)
//        {
//            snake_x[i] = snake_size;
//        }
//        else
//        {
//            snake_x[i] = i;
//        }
//    }
    //устанавливаем ее в поле
    for (int i = 0; i < snake_size; i++)
    {
        if (i == 0)
        {
            field[snake_x[i]] = HEAD_SYMBOL;
        }
        else
        {
            field[snake_x[i]] = TAIL_SYMBOL;
        }
    }
   
    //Генерация позиции еды для змейки на поле
    if (!food_flag)
    {
        do
        {
            food_x = rand() % L + 1;
        } while (field[food_x] != field_symbol);
        food_flag = true;
    }
    //Устанавливаем еду в поле
    field[food_x] = food_symbol;

    //Печатаем начальное поле для змейки
    print(field, COLUMNS);

    unsigned int user_case;
    //Вывод приглашения к игре
    std::cout << "Please enter anykey for start game";
    game_on = false;
    user_case = _getch();
    if (user_case != 27)
    {
        game_on = true;
    }
    else
    {
        return 0;
    }
    while (game_on)
    {
        std::cout << "\nInsert symble for determining the direction: right(->) or left(<-)";
#ifdef AUTOMATIC 
        if (_kbhit()) \
       { \
           user_case = _getch(); \
           if (user_case == 27) \
           { \
               game_on = false; \
               break; \
           } \
           else if (user_case != 224) \
           { \
               std::cout << "Incorrect symbol";                \
           } \
           else \
           { \
               user_case = _getch(); \
           } \
       } 
#else    
          user_case = _getch(); \
            if (user_case == 27) \
            { \
                game_on = false; \
                break; \
            } \
            else if (user_case != 224) \
            { \
                std::cout << "Incorrect symbol";                \
            } \
            else \
            { \
                user_case = _getch(); \
            }         
#endif
        switch (user_case)
        {
        case DIRECTION::right:
            game_on = true;
            break;
        case DIRECTION::left:
            game_on = true;
            break;
        default:
            //std::cout << "Incorrect symbol!";
            break;
        }

        //двигаем змейку                                            //-------- //321-------  //-432-----  //-432-----
        //положение змейки

        for (int i = snake_size - 1; i > 0; i--)
        {
            snake_x[i] = snake_x[i - 1];
        }

        if (user_case == DIRECTION::right)
        {
            //std::cout << "Зашли в right\n";
            snake_x[0]++;
            if (snake_x[0] >= COLUMNS - 1)
            {
                snake_x[0] = 1;
            }
        }
        if (user_case == DIRECTION::left)
        {
            //std::cout << "Зашли в left\n";
            snake_x[0]--;
            if (snake_x[0] < 1)
            {
                snake_x[0] = COLUMNS - 1;
            }
        }
        //Генерация позиции еды для змейки на поле
        if (!food_flag)
        {
            do
            {
                food_x = rand() % L + 1;
            } while (field[food_x] != field_symbol);
            food_flag = true;
        }
        //проверяем совпадение головы змейки и координат еды
        if (snake_x[0] == food_x)
        {
            snake_size++;
            if (snake_size == L)
            {
                std::cout << "Game over!\n";
                return 0;
            }
            food_flag = false;
        }

        //Очищаем игровое поле
        for (int i = 1; i < COLUMNS - 1; i++)
        {
            field[i] = field_symbol;
        }
        //Устанавливаем еду в поле
        field[food_x] = food_symbol;
        for (int i = 0; i < snake_size; i++)
        {
            if (i == 0)
            {
                field[snake_x[i]] = HEAD_SYMBOL;
            }
            else
            {
                field[snake_x[i]] = TAIL_SYMBOL;
            }
        }
        Sleep(timeout);
        //Sleep(300);
        print(field, COLUMNS);
    }

    return 0;
}
