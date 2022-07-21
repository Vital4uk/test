//простий калькулятор 
#include <iostream>
#include <string>
#include <vector>

//функція введення числа
//повертає десяткове число
//запобігає некоректному вводу числа
double get_number() 
{
	while (true)
	{
		std::cout << "Введіть число: \n";
		double number = 0.0;
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
char get_operation()
{
	while (true)
	{
		std::cout << "Введіть оператор '+' '-' '*' '/': \n";
		char operation;
		std::cin >> operation;
		std::cin.ignore(32767,'\n'); //забирає лишні введені символи 
		if ('+' == operation || '-' == operation || '*' == operation || '/' == operation)
		{
			return operation;
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
std::string get_action_word (char operation)
{
	switch (operation)
	{
		case '+':
			return { "Сума " };
		case '-':
			return { "Різниця " };
		case '*':
			return { "Добуток " };
		case '/':
			return { "Частка " };
	}
	return {};
}	

//функція яка виконує введену дію
//між введеними числами
//приймає введені числа і оператор
//вертає вирахувану дію
double do_action (char operation, double val1, double val2)
{
	switch (operation)
	{
		case '+':
			return { val1+val2 };
		case '-':
			return { val1-val2 };
		case '*':
			return { val1*val2 };
		case '/':
			return { val1/val2 };
	}
	return {};
}	

int main ()
{
	double val1 = get_number();
	double val2 = get_number();
	char operat = get_operation();
	std::string action_word = get_action_word(operat);
	double action = do_action(operat, val1, val2);
	
	std::cout << action_word << val1 << " i " << val2 << " дорівнює " << action << "\n";
	
	return 0;
}
