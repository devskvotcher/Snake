#include <iostream>
#include <conio.h>
#include "game.h"
#include "field.h"
#include "snake.h"
#include "const.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
//#define AUTOMATIC
void print(char* field, const int SIZE)
{
    system("cls");
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
    //Очистка всего игрового поля
     system("cls");
    for (int i = 0; i < COLUMNS; i++)
    {
        field[i] = field_symbol;
    }
    //Задание начального положения змейки
    snake_x[0] = snake_size;
    field[0] = border_symbol;
    field[COLUMNS - 1] = border_symbol;
    print(field, COLUMNS);
    unsigned int user_case;
    //Вывод приглашения к игре
    std::cout << "Insert symble for determining the direction: right(->) or left(<-)";
    user_case = _getch();
    if (user_case != 224)
    {
        std::cout << "Incorrect symbol\n";
    }
    else
    {
        user_case = _getch();
    }
              
        switch (user_case)
        {
        case DIRECTION::right:
            /*field[snake_x[0]] = HEAD_SYMBOL;
            if (snake_x[0] > 1)
            {
                for (size_t i = 1; i < snake_x[0]; i++)
                {
                    field[i] = TAIL_SYMBOL;
                }
            }*/
            field[snake_x[0]] = HEAD_SYMBOL;
            if (snake_x[0] > 1)
            {
                for (int i = snake_x[0]-1; i > 0; i--)
                {
                    field[i] = TAIL_SYMBOL;
                }
            }
            print(field, COLUMNS);
            std::cout << "\nPress any key for start game\n";
            _getch();
            do
            {
                int temp;
                temp = field[COLUMNS - 2];
                for (int i = COLUMNS - 2; i > 0; i--)
                {
                    field[i] = field[i - 1];
                }
                field[1] = temp;
                print(field, COLUMNS);
                /*Sleep(timeout);
                system("cls");
                if (_kbhit())
                {
                    user_case = _getch();
                    if (user_case == 27)
                    {
                        game_on = false;
                    }
                }*/
                #ifdef AUTOMATIC   // автоматический режим
                Sleep(timeout); \
                    system("cls"); \
                    if (_kbhit())       \
                    {                   \
                        user_case = _getch(); \
                        if (user_case == 27)  \
                        { \
                            game_on = false; \
                        } \
                    } 
                #else \  //пошаговый режим
                user_case = _getch(); \
                    if (user_case == 27)  \
                    { \
                        game_on = false; \
                    }
                #endif
            } while (game_on);
            break;
        case DIRECTION::left:
            field[L-snake_x[0]+1] = HEAD_SYMBOL;
            if (snake_x[0] > 1)
            {
                for (size_t i = L - snake_x[0] + 2; i <= COLUMNS - 2; i++)
                {
                    field[i] = TAIL_SYMBOL;
                }
            }
            print(field, COLUMNS);
            std::cout << "\nPress any key for start game\n";
            _getch();
            do
            {
                int temp;
                temp = field[1];
                for (int i = 2; i <= COLUMNS - 2; i++)
                {
                    field[i-1] = field[i];
                }
                field[COLUMNS-2] = temp;
                print(field, COLUMNS);
                /*Sleep(timeout);
                system("cls");
                if (_kbhit())
                {
                    user_case = _getch();
                    if (user_case == 27)
                    {
                        game_on = false;
                    }
                }*/
                #ifdef AUTOMATIC   // автоматический режим
                Sleep(timeout); \
                    system("cls"); \
                    if (_kbhit())       \
                    {                   \
                        user_case = _getch(); \
                        if (user_case == 27)  \
                        { \
                            game_on = false; \
                        } \
                    }
                #else \  //пошаговый режим
                user_case = _getch(); \
                    if (user_case == 27)  \
                    { \
                        game_on = false; \
                    }
                #endif
            } while (game_on);
            break;
            default:
                std::cout << "Вы ввели некорректный символ";
            break;

        }

        //Очистка всего игрового поля
        system("cls");
        for (int i = 0; i < COLUMNS; i++)
        {
            field[i] = field_symbol;
        }
        //Задание начального положения змейки
        //Вывод приглашения к игре
        std::cout << "Insert snake size=";
        std::cin >> snake_size;
        game_on = true;
        snake_x[0] = snake_size;
        field[0] = border_symbol;
        field[COLUMNS - 1] = border_symbol;
        print(field, COLUMNS);
        std::cout << "Insert symble for determining the direction: right(->) or left(<-)";
        user_case = _getch();
        if (user_case != 224)
        {
            std::cout << "Incorrect symbol\n";
        }
        else
        {
            user_case = _getch();
        }

        switch (user_case)
        {
        case DIRECTION::right:
            /*field[snake_x[0]] = HEAD_SYMBOL;
            if (snake_x[0] > 1)
            {
                for (size_t i = 1; i < snake_x[0]; i++)
                {
                    field[i] = TAIL_SYMBOL;
                }
            }*/
            field[snake_x[0]] = HEAD_SYMBOL;
            if (snake_x[0] > 1)
            {
                for (size_t i = snake_x[0] - 1; i > 0; i--)
                {
                    field[i] = TAIL_SYMBOL;
                }
            }
            print(field, COLUMNS);
            std::cout << "\nPress any key for start game\n";
            _getch();
            do
            {
                int temp;
                temp = field[COLUMNS - 2];
                for (int i = COLUMNS - 2; i > 0; i--)
                {
                    field[i] = field[i - 1];
                }
                field[1] = temp;
                print(field, COLUMNS);
                /*Sleep(timeout);
                system("cls");
                if (_kbhit())
                {
                    user_case = _getch();
                    if (user_case == 27)
                    {
                        game_on = false;
                    }
                }*/
#ifdef AUTOMATIC   // автоматический режим
                Sleep(timeout); \
                    system("cls"); \
                    if (_kbhit())       \
                    {                   \
                        user_case = _getch(); \
                        if (user_case == 27)  \
                        { \
                            game_on = false; \
                        } \
                    }
#else \  //пошаговый режим
                user_case = _getch(); \
                    if (user_case == 27)  \
                    { \
                        game_on = false; \
                    }
#endif
            } while (game_on);
            break;
        case DIRECTION::left:
            field[L - snake_x[0] + 1] = HEAD_SYMBOL;
            if (snake_x[0] > 1)
            {
                for (size_t i = L - snake_x[0] + 2; i <= COLUMNS - 2; i++)
                {
                    field[i] = TAIL_SYMBOL;
                }
            }
            print(field, COLUMNS);
            std::cout << "\nPress any key for start game\n";
            _getch();
            do
            {
                int temp;
                temp = field[1];
                for (int i = 2; i <= COLUMNS - 2; i++)
                {
                    field[i - 1] = field[i];
                }
                field[COLUMNS - 2] = temp;
                print(field, COLUMNS);
                /*Sleep(timeout);
                system("cls");
                if (_kbhit())
                {
                    user_case = _getch();
                    if (user_case == 27)
                    {
                        game_on = false;
                    }
                }*/
#ifdef AUTOMATIC   // автоматический режим
                Sleep(timeout); \
                    system("cls"); \
                    if (_kbhit())       \
                    {                   \
                        user_case = _getch(); \
                        if (user_case == 27)  \
                        { \
                            game_on = false; \
                        } \
                    }
#else \  //пошаговый режим
                user_case = _getch(); \
                    if (user_case == 27)  \
                    { \
                        game_on = false; \
                    }
#endif
            } while (game_on);
            break;
        default:
            std::cout << "Вы ввели некорректный символ";
            break;

        }
        

    return 0;
}
