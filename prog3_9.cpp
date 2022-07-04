//програма виводить три цілих числа в порядку зростання
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

			
int main()
{
	int val1, val2, val3;
	int rez1, rez2, rez3, tmp;
	std::cout << "Введіть три цілих числа: " << std::endl;
	std::cin >> val1 >> val2 >> val3;
	if (val1 <= val2) 
	{
		rez1 = val1;
		rez2 = val2;
		rez3 = val3;
	}
	else 
	{	rez1 = val2;
		rez2 = val1;
	}
	if (val1 >= val2) 
	{
		if (val1 >= val3) 
		{
			rez3 = val1;
			rez2 = val3; 
		}
		else 
		{	rez2 = val1;
			rez3 = val3;
		} 
	}
	else 
	{	if (val1 >= val3) 
		{ 
			rez1 = val3;
			rez2 = val1;
			rez3 = val2;
		}	
		else 
		{	if (val2 > val3) 
			{ 
			rez2 = val3;
			rez3 = val2;	
			}	
		}		
	}

	if (rez1 > rez2) 
	{
		tmp = rez1;
		rez1 = rez2;
		rez2 = tmp;
	}

	std::cout << "Числа в зростаючому порядку: " << rez1 << ", " << rez2 << ", " << rez3 << "." << std::endl;
	return 0;
}
