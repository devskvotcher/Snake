#pragma once

//Массив игрового поля
#include <iostream>
#include "const.h"
using std::cout;
using std::endl;
//extern char field[];

void init_field(char** field, int field_columns, int field_rows);
void clear_field(char** field, int field_columns, int field_rows);
void print_field(char** field, int field_columns, int field_rows);

bool create_field(char** &sub_field, char* &field, int field_columns, int field_rows);
void destroy_field(char** &sub_field, char* &field, int field_columns, int field_rows);
