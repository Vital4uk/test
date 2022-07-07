//програма виводить список чисел і їх квадратів використовуючи функцію square()
//без використання оператора множення
#include <iostream>
#include <string>
#include <vector>

int square(int x)
{
	int j = 0;
	int y = 0;

	while (j<x)
	{
		y += x;
		++j;
	}
	return y; 
}



int main()
{
	for (int i = 0; i < 100; ++i)
	{
		std::cout << i << "\t" << square(i) << "\n";
	}
	
	return 0;	
}
