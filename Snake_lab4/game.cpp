#include "game.h"
extern char snake[];
extern char field[];
extern const int COLUMNS;
extern const char field_symbol;
extern unsigned int snake_size;
extern int snake_x[];
void init_game()
{
    //������� ����� �������� ����
    system("cls");
    //���������� �������� ����
    for (int i = 1; i < COLUMNS - 1; i++)
    {
        field[i] = field_symbol;
    }
    //������� ������ 
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