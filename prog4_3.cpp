//програма виводить список від а до z та через табуляцію навпроти числа від 97 до 122
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{

	char letter = 'a';
	int i = 97;
			
	while (i<123)
	{
		std::cout << letter << "\t" << i << "\n";
		++i;
		++letter;
	}
	
}
