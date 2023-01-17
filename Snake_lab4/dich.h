#include <iostream>
#include <conio.h>
#include "game.h"
#include "field.h"
#include "snake.h"
#include "const.h"
#include "food.h"
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
    //������� ����� �������� ����
    system("cls");
    for (int i = 0; i < COLUMNS; i++)
    {
        field[i] = field_symbol;
    }
    //������� ���������� ��������� ������
    snake_x[0] = snake_size;
    field[0] = border_symbol;
    field[COLUMNS - 1] = border_symbol;
    print(field, COLUMNS);
    unsigned int user_case;
    //����� ����������� � ����
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
    // ��������� ��� ��� ������
    switch (user_case)
    {
    case DIRECTION::right:
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
            for (int i = 1; i < COLUMNS - 2; i++)
            {
                if ((food_flag == true) && (field[i] == HEAD_SYMBOL) && (field[i] == field[food_x]))
                {
                    food_flag = false;
                    for (size_t j = COLUMNS - 2; j > 0; j--)
                    {
                        if ((snake_size < 2) && (field[j] == HEAD_SYMBOL) && (field[j - 1] == field_symbol) || (snake_size > 1) && (field[j] == TAIL_SYMBOL) && (field[j - 1] == field_symbol))
                        {
                            field[j - 1] = TAIL_SYMBOL;
                            break;
                        }
                    }
                    snake_size++;
                }
                if (food_flag != true)
                {
                    food_x = rand() % L + 1;
                    if (field[food_x] == field_symbol)
                    {
                        food_flag = true;
                        field[food_x] = food_symbol;
                    }
                }
                if (field[i] != field[food_x] || field[i - 1] != field[food_x])
                {
                    field[i] = field[i - 1];
                }

            }
            field[1] = temp;
            print(field, COLUMNS);
#ifdef AUTOMATIC   // �������������� �����
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
#else \  //��������� �����
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
#ifdef AUTOMATIC   // �������������� �����
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
#else \  //��������� �����
            user_case = _getch(); \
                if (user_case == 27)  \
                { \
                    game_on = false; \
                }
#endif
        } while (game_on);
        break;
    default:
        std::cout << "�� ����� ������������ ������";
        break;

    }

    //������� ����� �������� ����
    system("cls");
    for (int i = 0; i < COLUMNS; i++)
    {
        field[i] = field_symbol;
    }
    //������� ���������� ��������� ������
    //����� ����������� � ����
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
#ifdef AUTOMATIC   // �������������� �����
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
#else \  //��������� �����
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
#ifdef AUTOMATIC   // �������������� �����
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
#else \  //��������� �����
            user_case = _getch(); \
                if (user_case == 27)  \
                { \
                    game_on = false; \
                }
#endif
        } while (game_on);
        break;
    default:
        std::cout << "�� ����� ������������ ������";
        break;

    }


    return 0;
}
