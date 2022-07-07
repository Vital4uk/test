//програма порівнює два введені числа
//і виводить результат порівняння 
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::cout << "Введіть два числа: \n";
	std::vector<double> numbers;
	double temp, diff;
	int i = 0;
	while (i < 2)
	{
		std::cin >> temp;
		numbers.push_back(temp);
		std::cout << numbers[i] << "\n";
		++i;
	}
	if (numbers[0] > numbers[1])
	{
		diff = numbers[0]-numbers[1];
	}
	else
	{
		diff = numbers[1]-numbers[0];
	}
	if (numbers[0] > numbers[1] && diff >= 1.0/100)
	{
		std::cout << "Найменше значення дорівнє: "<< numbers[1] << "\n";
		std::cout << "Найбільше значення дорівнє: "<< numbers[0] << "\n";
	}
	else if (numbers[0] < numbers [1] && diff >= 1.0/100)
	{
		std::cout << "Найменше значення дорівнє: "<< numbers[0] << "\n";
		std::cout << "Найбільше значення дорівнє: "<< numbers[1] << "\n";
	}
	else if (numbers[0] == numbers[1])
	{
		std::cout << "Числа: " << numbers[0] << " i " << numbers[1] << " рівні.\n";
	}
	else if (diff < 1.0/100)
	{
		std::cout << "Числа: " << numbers[0] << " i " << numbers[1] << " майже рівні.\n";
	}
	return 0;	
}
