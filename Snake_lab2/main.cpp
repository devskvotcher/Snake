#include <iostream>
#include "const.h"
#include <Windows.h>
#include "const.h"
#include "snake.h"
#include "game.h"
int main()
{
	if (snake_size == 1)
	{
		for (size_t i = 0; i < COLUMNS; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				std::cout << " ";
			}
			std::cout << HEAD_SYMBOL;
			Sleep(timeout);
			system("cls");
		}
	}
	else
	{
		for (size_t i = 0; i < COLUMNS; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				std::cout << " ";
			}
			for (size_t j = 0; j < snake_size-1; j++)
			{
				std::cout << TAIL_SYMBOL;
			}
			std::cout << HEAD_SYMBOL;
			Sleep(timeout);
			system("cls");
		}
	}
	
	return 0;
}