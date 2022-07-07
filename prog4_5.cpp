//програма виводить список чисел і їх квадратів використовуючи функцію square()
//без використання оператора множення
#include <iostream>
#include <string>

int square(int number)
{
	int j = 0;
	int square_number = 0;

	while (j<number)
	{
		square_number += number;
		++j;
	}
	return square_number; 
}

int main()
{
	for (int i = 0; i < 100; ++i)
	{
		std::cout << i << "\t" << square(i) << "\n";
	}
	return 0;	
}
