#pragma once

//��������� ��� ����������� ���� ���� � ������� ����, 
//� ����� ������������ �������� ����� ������

//const int columns =16;					//����� �������� ���� �� �����������, ������� ��������� �������
//const int rows = 32;					//����� �������� ���� �� ���������, ������� ��������� �������
const char tail_symbol = '#';				//������ ��� ������ ������
const char head_symbol='@';				//������ ��� ������ ������
const char field_symbol=' ';			//������ ��� ���������� ���� ����
const char border_symbol='*';			//������ ��� ������� ���� ����
const int L = 80;// (columns - 2);//const int L = (columns)>2?((columns - 2)):1;	//������������ ������ ������� ������
const int H = 160; //(rows - 2);
const char food_symbol = '+';			//������ ���
/*
const, �� ������ ���� > ����� �������� ����-2
*/
enum DIRECTION { MOVE_UP, MOVE_DOWN, MOVE_RIGHT, MOVE_LEFT };		//������������ ������������ ���������
enum KEYS {ESC=27, UP=72, DOWN=80, RIGHT=77, LEFT=75};					//��������� ��� ��������� ������������� �����(������������ �� ��������(���� ������)_1(������������ ����)�)


