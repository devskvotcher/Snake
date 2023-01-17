#include <conio.h>
#include <Windows.h>
#include "food.h"
#include "const.h"
#include <iostream>
extern char snake[];
extern char field[];
extern const int COLUMNS;
extern const char field_symbol;
extern unsigned int snake_size;
extern int snake_x[];
extern const char HEAD_SYMBOL;
extern const char TAIL_SYMBOL;
void init_game()
{
    //Очистка всего игрового поля
    system("cls");
    //Подготовка игрового поля
    for (int i = 1; i < COLUMNS - 1; i++)
    {
        field[i] = field_symbol;
    }
    //Создаем змейку 
    for (int i = 0; i < snake_size; i++)
    {
        if (i == 0)
        {
            snake_x[i] = snake_size;
        }
        else
        {
            snake_x[i] = i;
        }
    }
}
void set_snake()
{
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
}
void setFood()
{
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
}
void clearField()
{
    for (int i = 1; i < COLUMNS - 1; i++)
    {
        field[i] = field_symbol;
    }
}
void handle_cmd()
{
    unsigned int user_case;
    //Вывод приглашения к игре
    std::cout << "Please enter anykey for start game";
    bool game_on = false;
    user_case = _getch();
    if (user_case != 27)
    {
        game_on = true;
    }
    else
    {
        exit(0);
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
        //Пользовательский ввод
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
    }
}
void check_game()
{
    if (snake_size == L)
    {
        std::cout << "Game over!\n";
        exit(0);
    }
}
bool check_eating()
{
    if (snake_x[0] == food_x)
    {
        snake_size++;
        check_game();
        food_flag = false;
    }
    return true;
}

    


