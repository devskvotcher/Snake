#include "field.h"



//Массив символов игрового поля
char field[columns];

void init_field(void) {
	const int rows = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			//field[j] = ' ';
			if ((i > 0 && i < (rows -1)) || (j>0 && j<(L+1))) {
				field[j] = ' ';
			}
			else {
				field[j] = border_symbol;
			}
		}
	}

}
//Массив игрового поля заполняется символом-очистителем (например, пробелом
void clear_field(void) {
	const int rows = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 1; j <= L; j++) {	
				field[j] = ' ';
		}
	}
}
//Массив игрового поля выводится на экран
void print_field(void) {
	const int rows = 1;
	//upper border
	for (int i = 0; i < columns; i++) {
		std::cout << border_symbol;
	}
	cout << endl;
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {
			std::cout << field[j];
			//if (/*(i > 0 && i < (rows - 1)) ||*/ (j > 0 && j < columns )) {
			//	std::cout << field[j];
			//}
			//else {
			//	std::cout << border_symbol;
			//}
			
		}
		cout << endl;
	}
	//lower border
	for (int i = 0; i < columns; i++) {
		std::cout << border_symbol;
	}
	std::cout << std::endl;
}

