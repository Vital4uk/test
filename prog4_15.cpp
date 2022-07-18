//простий калькулятор 
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

//функція введення числа
//повертає десяткове число
//запобігає некоректному вводу числа
double get_number() 
{
	while (true)
	{
		std::cout << "Введіть число: \n";
		double number = 0;
       		std::cin >> number;
		if (std::cin.fail())	//якщо попереднє введене значення не вдале
		{
			std::cin.clear(); //повертаємо cin в звичайний режи роботи
			std::cin.ignore(32767, '\n'); //і видаляємо значення попереднього вводу
			std::cout << "Введене не коректне значення, спробуйте знову. \n";			      //і вхідного буфера
		}
		else
		{
			return number;
		}
	}
}	

//функця вводу оператора
//повертає опертатор + - * /
char get_operat()
{
	while (true)
	{
		std::cout << "Введіть оператор '+' '-' '*' '/': \n";
		char i_operat = ' ';
		std::cin >> i_operat;
		std::cin.ignore(32767,'\n'); //забирає лишні введені символи 
		if (i_operat == '+' || i_operat == '-' || i_operat == '*' || i_operat == '/')
		{
			return i_operat;
		}
		else
		{
			std::cout << "Ви ввели не коректний оператор, спробуйте знову. \n";
		}
        }
}

//функція визначення введеного оператора
//і запис його словом
//приймає введений опертор
//вертає оператор словом
std::string get_action_word (char i_operat)
{
	std::string action_word = " ";
	
	if (i_operat == '+')
	{
		action_word = "Сума ";
	}
	else if (i_operat == '-')
	{
		action_word = "Різниця ";
	}
	else if (i_operat == '*')
	{
		action_word = "Добуток ";
	}
	else
	{
		action_word = "Частка ";
	}
	return action_word;
}	

//функція яка виконує введену дію
//між введеними числами
//приймає введені числа і оператор
//вертає вирахувану дію
double do_action (char i_operat, double val1, double val2)
{
	double do_action = 0;
	
	if (i_operat == '+')
	{
		do_action = val1+val2;
	}
	else if (i_operat == '-')
	{
		do_action = val1-val2;
	}
	else if (i_operat == '*')
	{
		do_action = val1*val2;
	}
	else if (i_operat == '/')
	{
		do_action = val1/val2;
	}
	return do_action;
}	

int main ()
{
	double val1 = get_number();
	double val2 = get_number();
	char operat = get_operat();
	std::string action_word = get_action_word(operat);
	double action = do_action(operat, val1, val2);
	
	std::cout << action_word << val1 << " i " << val2 << " дорівнює " << action << "\n";
	
	return 0;
}
