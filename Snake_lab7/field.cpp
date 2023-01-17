#include "field.h"

//Массив символов игрового поля
//char field[columns];

void init_field(char (*field)[rows]) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			//field[j] = ' ';
			if ((i > 0 && i < (H+1)) && (j>0 && j<(L+1))) {
				field[j][i] = ' ';
			}
			else {
				field[j][i] = border_symbol;
			}
		}
	}

}
//Массив игрового поля заполняется символом-очистителем (например, пробелом
void clear_field(char (*field)[rows]) {
	
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= L; j++) {	
				field[j][i] = ' ';
		}
	}
}
//Массив игрового поля выводится на экран
void print_field(char (*field)[rows]) {
	//upper border
	//for (int i = 0; i < columns; i++) {
	//	std::cout << border_symbol;
	//}
	//cout << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << field[j][i];	
		}
		cout << endl;
	}
	//lower border
	//for (int i = 0; i < columns; i++) {
	//	std::cout << border_symbol;
	//}
	//std::cout << std::endl;
}

