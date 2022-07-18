//програма виводить числом введені значення словами і цифрами 
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

//функція для прийому чисел словами і цифрами
//Приймає числа, трасформує вектор з введеними числами 
//із string в double
//повертає число складене із окремо введених цифр
double get_number ()
{
	double number = 0;
	const std::vector<std::string> numbers_in_words = {"zero","one","two","three","four","five","six","seven","eight","nine","0","1","2","3","4","5","6","7","8","9"};
	std::vector<std::string> input_value;
	std::vector<std::string> final_input_value;
	std::vector<double> separate_numbers;
	std::cout << "Введіть число цифрами або словами з назвою числа аглійською мовою, кожне число через пробіл: \n";
	std::cout << "Враховані будуть тільки правильно введені значення. \n" << "Для завершення введіть '|' \n";
	//цикл для введення цифр
	//завершується якщо ввести символ '|'
	for (std::string temp; std::cin >> temp;)
	{
		if (temp == "|")
		{
			break;
		}
		input_value.push_back(temp);
	}
	//цикл порівняння введених значень з константними для
	//відкидання помилково введених
	//правильно введені записуються в остаточний вектор
	for (int i = 0; i < input_value.size(); ++i)
	{
		for (const std::string number_name : numbers_in_words)
		{
			if (number_name == input_value[i])
			{
				final_input_value.push_back(input_value[i]);
			}
		}
	}
	
	//числа словами дорівнюють числу їх місця у векторі
	//циклами визначаємо місце у константному векторі введеного числа
	//і запам'ятовуємо це число у новому векторі	
	for (int i = 0; i < final_input_value.size(); ++i)
	{
		for (int l = 0; l < numbers_in_words.size(); ++l)
                {
                	if (numbers_in_words[l] == final_input_value[i])
                        {
                        	if (l >= 10)
				{
					separate_numbers.push_back(l-10);
				}
				else
				{
					separate_numbers.push_back(l);
				}
                        }
                }
	}
	
	//переводимо вектор з числами в одне число	
	int k = separate_numbers.size()-1;
	for (int j = 0; j < separate_numbers.size(); ++j)
	{
		number += separate_numbers[j]*pow(10,k);
		--k;
	}
	return number;
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



