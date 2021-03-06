//гра 'камінь ножиці бумага'
#include <iostream>
#include <string>
#include <stdlib.h>	//для виклику функції rand()
#include <time.h>	//для виклику функції time()

//функція генерує випадкове число у визначеному діапазоні
//приймає мінімальне і максимальне число діапазону
//повертає випадкове ціле число з вибраного діапазону
int get_random_number (int min, int max)
{
	//установка генератора випадкових числел (srand())
	//тобто задається число, на основі якого вираховується послідовність випадкових чисел з допомогою rand()
	//число задається функцією time(), NULL - це число мілісекунд, які
	//пройшли від 01.01.1970 року 
	srand(time(NULL));	
	//вираховуємо випадкове число
	int num = min + rand() % (max - min + 1);
	return num;
}

//функція приймає випадковий номер від 0 до 2
//повертає слово або камінь або ножиці або бумага
std::string get_word (int number)
{
	switch (number)
	{
		case 0:
			return { "Камінь " };
		case 1:
			return { "Ножиці " };
		case 2:
			return { "Бумага " };
	}
	return {};
}

int main ()
{
	int number = 0;
	std::string word;
	std::cout << "Вас вітає гра камінь ножиці бумага.\n";
	std::cout << "Для продовження гри натисність enter \n";
	
	//поки вводимо enter цикл продовжується
	while (std::cin.get() == '\n')
	{
		//генеруємо випадкове число від 0 до 2
		number = get_random_number(0,2);
		//на основі згенерованого числа визначаємо потрібне слово для гри
		word = get_word (number);
	
		std::cout << word << "\n" << std::endl;
		std::cout << "Для продовження гри натисність enter \n";
	}
	return 0;
}



