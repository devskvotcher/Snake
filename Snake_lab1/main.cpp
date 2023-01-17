#include <iostream>
#include <conio.h>
int main()
{
//-----------------Первый способ------------------------------------------------
//	char user_case_type1;
//	while (1)
//	{
//
//		std::cout << "Insert symble for determining the direction=";
//		std::cin >> user_case_type1;
//		switch (user_case_type1)
//		{
//		case 'a':
//			std::cout << "<\n";
//			break;
//		case 'd':
//			std::cout << ">\n";
//			break;
//		case 'w':
//			std::cout << "^\n";
//			break;
//		case 's':
//			std::cout << "v\n";
//			break;
//		case '0':
//			std::cout << "Good bye";
//			return 0;
//		default:
//			std::cout << "Incorrect symbol";
//			break;
//		}
//    }
//
////-----------------Второй способ------------------------------------------------
//	enum keys_type1
//	{
//	 a=97,
//	 d=100,
//	 s=115,
//	 w=119,
//	 exit1=27
//	}; 
//	int user_case_type2;
//	std::cout << "Insert symble for determining the direction\n";
//	while (1)
//	{
//
//		
//		user_case_type2 = _getch();
//		switch (user_case_type2)
//		{
//		case keys_type1::a:
//			std::cout << "<\n";
//			break;
//		case keys_type1::d:
//			std::cout << ">\n";
//			break;
//		case keys_type1::w:
//			std::cout << "^\n";
//			break;
//		case keys_type1::s:
//			std::cout << "v\n";
//			break;
//		case keys_type1::exit1:
//			std::cout << "Good bye";
//			return 0;
//		default:
//			std::cout << "Incorrect symbol";
//			break;
//		}
//	}
//----------------------------Третий способ-----------------------------------------------
	enum keys
	{
	 left_arrow=75,
	 right_arrow =77,
	 down_arrow=80,
	 up_arrow=72,
	 exit=27	 
	}; 
	unsigned int user_case;
std::cout << "Insert symble for determining the direction\n";
while (1)
{
	user_case = _getch();

	if (user_case == keys::exit)
	{
		std::cout << "Good Bye!";
		return 0;
	}
	else if (user_case != 224)
	{
		std::cout << "Incorrect symbol\n";
	}
	else
	{
		user_case = _getch();
		switch (user_case)
		{
			case keys::left_arrow:
				std::cout << "<\n";
				break;
			case keys::right_arrow:
				std::cout << ">\n";
				break;
			case keys::up_arrow:
				std::cout << "^\n";
				break;
			case keys::down_arrow:
				std::cout << "v\n";
				break;
			default:
				std::cout << "Incorrect symbol";
				break;
	}
	}
	
}
	return 0;
}