#pragma once

//Массив игрового поля
#include <iostream>
#include "const.h"
using std::cout;
using std::endl;
extern char field[];

void init_field(void);
void clear_field(void);
void print_field(void);
