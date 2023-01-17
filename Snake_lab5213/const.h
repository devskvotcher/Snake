#pragma once
const int COLUMNS = 12;
const char TAIL_SYMBOL = '#';
const char HEAD_SYMBOL = '@';
const char field_symbol = ' ';
const char border_symbol= '*';
const int L = COLUMNS - 2;
const char food_symbol = '+';
enum keys
{
	left_arrow = 75,
	right_arrow = 77,
	down_arrow = 80,
	up_arrow = 72,
	exit1 = 27
};
enum DIRECTION
{
	right = keys::right_arrow,
	left = keys::left_arrow
};
