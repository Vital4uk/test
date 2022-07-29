//програма приймає набір чисел і визначає
//ноду масиву, найбільше і найменше число
#include <iostream>
#include <vector>
#include <limits>


//функція введення кількості одиниць виміру
//повертає десяткове число відстані
//запобігає некоректному вводу числа
double get_number() 
{
	while (true)
	{
		std::cout << "Введіть число: \n"
			  << "Для виходу введіть 10 чисел.\n";
		double num = 0;
       		std::cin >> num;
		if (std::cin.fail())	//якщо попереднє введене значення не вдале
		{
			std::cin.clear(); //повертаємо cin в звичайний режи роботи
			std::cin.ignore(32767, '\n'); //і видаляємо значення попереднього вводу
			std::cout << "Введене не коректне значення. \n";			      //і вхідного буфера
		}
		else
		{
			return num;
		}
	}
}	


int main()
{
	int running = 0;
	double number = 0.0;	//для введених чисел
	double min_number = std::numeric_limits<double>::max(); //присвоюємо найбільше з можливих чисел double
	double max_number = std::numeric_limits<double>::lowest();//присвоюємо найменше з можливих числел double
	std::vector<double> all_numbers; // вектор для введених значень
//	for (int i = 0; i < std::numeric_limits<double>::max(); ++i) //цикл вводу значень
	while (running != 10)
	{
		number = get_number();

//		if (std::cin.get() == '\n') //вихід з циклу
//		{
//			break;
//		}	
			
		all_numbers.push_back(number);
		++running;

	}
	//рахуємо в вектор кількість однакових значень кожного введеного числа
	//відслідковуємо максимальне і мінімальне число
	std::vector<double> max_count;
	for (int k = 0; k < all_numbers.size(); ++k)
	{
		int calc = 0;
		for (int l = 0; l < all_numbers.size(); ++l)
		{
			if (all_numbers[k] == all_numbers[l])
			{
				++calc;
			}
			
		}
		max_count.push_back(calc);

		if (all_numbers[k] <= min_number)
		{
			min_number = all_numbers[k];
		}
		if (all_numbers[k] >= max_number)
		{
			max_number = all_numbers[k];
		}
	}
	
	int max_num = max_count[0];
	std::vector<double> mode;
	//визначаємо найбільшу кількість однакових значень
	for (int m = 0; m < max_count.size(); ++m)
	{
		if (max_num < max_count[m])
		{
			max_num = max_count[m];
		}
	 	
	}
	//записуємо у вектор мода (числа з найбільшою кількістю повторів)
	//утворився вектор в якому числа, що мають найбільші значення, але дублюються
	//відносно своїх позицій у векотрі введення чисел
	for (int n = 0; n < max_count.size(); ++n)
	{
		if (max_num == max_count[n])
		{
			mode.push_back(all_numbers[n]);
		}
	}
	//визначаємо позиції, які дублюються і замінюємо їх на '0' 
	for (int p = 0; p < mode.size(); ++p)
	{
		int calc2 = 0;
		//проганяємо кожне число в векторі і порівнюємо його з іншими
		//якщо числа однакові, перше число залишаємо без змін
		//а інші числа замінюємо на '0'	
		for (int q = 0; q < mode.size(); ++q)
		{
			if (calc2 == 1 && mode[p] == mode[q])
			{
				mode[q] = 0;
			}
			if (mode[p] == mode[q])
			{
				++calc2;
			}
		}
	}
	//виводимо моду без замінених чисел на '0'
	std::cout << "------------------------ \n";
	std::cout << "Мода масиву чисел:" << "\n";
	for (double x : mode)
	{
		if (x != 0)
		{
			std::cout << x << "\n";
		}
	}
	std::cout << "------------------------ \n";

	if (all_numbers.size() == 0)
	{
		std::cout << "Не введено жодного значення. " << "\n";
	}
	else if (all_numbers.size() == 1)
	{
		std::cout << "Максимальне і мінімальне значення однакові: " << min_number << "\n";
	}
	else
	{
		std::cout << "Найменше введене значення: " << min_number << "\n";
		std::cout << "Найбільше введене значення: " << max_number << "\n";
	}
	return 0;	
}
