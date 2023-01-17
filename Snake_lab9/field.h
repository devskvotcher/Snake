#pragma once

//Массив игрового поля
#include <iostream>
#include "const.h"
//using std::cout;
//using std::endl;
//extern char field[];

struct FIELD {
    int columns = 0;					//Длина игрового поля по горизонтали, включая граничные элемент
    int rows = 0;                    //Длина игрового поля по вертикали
    char** field;                     //Массив игрового поля (двумерный динамический)
};


void init_field(char** field, int field_columns, int field_rows);
void clear_field(char** field, int field_columns, int field_rows);
void print_field(char** field, int field_columns, int field_rows);

bool create_field(char** &sub_field, char* &field, int field_columns, int field_rows);
void destroy_field(char** &sub_field, char* &field, int field_columns, int field_rows);

void init_field_struct(FIELD& field);
void clear_field_struct(FIELD& field);
void print_field_struct(const FIELD& field);

bool create_field_struct(FIELD& field);
void destroy_field_struct(FIELD& field);
