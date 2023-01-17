#pragma once

//Массив игрового поля
#include <iostream>
#include "const.h"
using std::cout;
using std::endl;
//extern char field[];

void init_field(char* field);
void clear_field(char* field);
void print_field(char* field);
