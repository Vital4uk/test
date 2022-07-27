//програма приймає набір слів
//ноду масиву, найбільше і найменше слова
#include <iostream>
#include <vector>
#include <algorithm>

//функція введення слів
//повертає фразу
std::string get_phrase() 
{
	std::cout << "Введіть запис: \n"
		  << "Для виходу введіть 'end'\n";
	std::string phrase;
	std::cin >> phrase;
	return phrase;
}	


int main()
{
	std::string word;	
	std::vector<std::string> all_words; // вектор для введених значень
	while (word != "end")
	{
		word = get_phrase();
		all_words.push_back(word);
	}
	//рахуємо в вектор кількість однакових значень кожного введеного слова
	std::vector<double> max_count;
	for (int i = 0; i < all_words.size(); ++i)
	{
		int calc = 0;
		for (int j = 0; j < all_words.size(); ++j)
		{
			if (all_words[i] == all_words[j])
			{
				++calc;
			}
		}
		max_count.push_back(calc);
	}
	
	int max_num = max_count[0];
	std::vector<std::string> mode;
	//визначаємо найбільшу кількість однакових значень
	for (int i = 0; i < max_count.size(); ++i)
	{
		if (max_num < max_count[i])
		{
			max_num = max_count[i];
		}
	 	
	}
	//записуємо у вектор мода (слова з найбільшою кількістю повторів)
	//утворився вектор в якому числа, що мають найбільші значення, але дублюються
	//відносно своїх позицій у векотрі введення слів
	for (int i = 0; i < max_count.size(); ++i)
	{
		if (max_num == max_count[i])
		{
			mode.push_back(all_words[i]);
		}
	}
	//визначаємо позиції, які дублюються і замінюємо їх на '0' 
	for (int i = 0; i < mode.size(); ++i)
	{
		int calc2 = 0;
		//проганяємо кожне слово в векторі і порівнюємо його з іншими
		//якщо слова однакові, перше слово залишаємо без змін
		//а інші числа замінюємо на '0'	
		for (int j = 0; j < mode.size(); ++j)
		{
			if (calc2 == 1 && mode[i] == mode[j])
			{
				mode[j] = "0";
			}
			if (mode[i] == mode[j])
			{
				++calc2;
			}
		}
	}
	//виводимо моду без замінених слів на '0'
	std::cout << "------------------------ \n";
	std::cout << "Мода масиву слів:" << "\n";
	for (std::string x : mode)
	{
		if (x != "0")
		{
			std::cout << x << "\n";
		}
	}
	std::cout << "------------------------ \n";
	//сортуємо масив для визначення найбільшого і найменшого значення
	std::sort(all_words.begin(), all_words.end());
	if (all_words.size() == 0)
	{
		std::cout << "Не введено жодного значення. " << "\n";
	}
	else if (all_words.size() == 1)
	{
		std::cout << "Максимальне і мінімальне значення однакові: " << all_words[0] << "\n";
	}
	else
	{
		std::cout << "Найменше введене значення: " << all_words[0] << "\n";
		std::cout << "Найбільше введене значення: " << all_words[all_words.size()-1] << "\n";
	}
	return 0;	
}
