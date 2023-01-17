#include "game.h"
//������� ����������� ����
bool game_on;
//delay timeout
unsigned int timeout ;
//��������������� ��������� �������� ���������� ����
void init_game(void) {
    srand(time(0));
	timeout = 500;
    snake_size = 1;
    game_on = true;
    food_flag=false;
}
//������ ��������������� � ������� ����
void set_snake(void) {

    //��������� ������
    for (int i = 0; i < snake_size; i++) {
        if (snake_x[i] != 0) {
            if (i == 0) {
                //��������� ������
                field[snake_x[i]] = head_symbol;
            }
            else {
                field[snake_x[i]] = tail_symbol;
            }
        }
    }
}
//��� ��������������� � ������� ����
void set_food(void) {

    field[food_x] = food_symbol;
}
//����������� �������� ����,��� �� ���� ���� ��������� ����� ��� ������������
void check_game(void) {
    if (game_on) {
        if (snake_size >= L) {
            game_on = false;
        }
        else {
            game_on = true;
        }
    }
}
//����������� �������� ����,��� ������ ����������� � �������� ����
void check_snake(void) {
    if (game_on) {
        if (snake_x[0] <= 0 || snake_x[0] >= columns - 1) {
            game_on = false;
        }
        else {
            game_on = true;
        }
    }
}
//����������� �������� ����, ��� ������ ����� ���
void check_eating(void) {
    if (game_on) {
        if (snake_x[0] == food_x) {
            food_flag = false;
        }
        else {
            food_flag = true;
        }
    }
}
//��������� ������� ������ � �������
void clear_snake(void) {

    //������� ������� ������
    for (int i = 0; i < snake_size; i++) {
        if (snake_x[i] != 0) {
            if (i == 0) {
                field[snake_x[i]] = ' ';
            }
            else {
                field[snake_x[i]] = ' ';
            }
        }
    }
}

void keyboard_scan(void) {
    //��������� ������� ������
    unsigned char direction1 = 0, direction2 = 0;

    direction1 = _getch();/////////////////////////��� ���     //_getch(); �  //system("PAUSE");

    if (KEYS::ESC == direction1 /*|| 224 == direction*/) {
        game_on = false;
        return;
    }
    else
    {
        if (224 == direction1)
        {
            direction2 = _getch();
            switch (direction2) {
                //left
            case KEYS::LEFT/*75*/:
                //std::cout << '@' << "left" << std::endl;
                direction = DIRECTION::MOVE_LEFT;
                game_on = true;
                break;
                //right
            case KEYS::RIGHT/*77*/:
                //std::cout << '@' << "right" << std::endl;
                direction = DIRECTION::MOVE_RIGHT;
                game_on = true;
                break;
                //up
            case KEYS::UP://72:
                //std::cout << '@' << "up" << std::endl;
                direction = DIRECTION::MOVE_UP;
                game_on = true;
                break;
                //down
            case KEYS::DOWN://80:
                //std::cout << '@' << "down" << std::endl;
                direction = DIRECTION::MOVE_DOWN;
                game_on = true;
                break;
                //exit
            case KEYS::ESC://27:
                //std::cout << '@' << "ESC" << std::endl;
                game_on = false;
                break;
            default:
                //std::cout << '@' << "def" << std::endl;
                game_on = true;
            }
        }
    }
}
