//програма вирішує квадратне рівняння
//a * x * 2 + b * x + c = 0;

#include <iostream>
#include <cmath>

//функція введення числа
//повертає десяткове число 
//запобігає некоректному вводу
double get_number() 
{
	while (true)
	{
		double num = 0;
       	std::cin >> num;
		if (std::cin.fail())	//якщо попереднє введене значення не вдале
		{
 			std::cin.clear(); //повертаємо cin в звичайний режим роботи
			std::cin.ignore(32767, '\n'); //і видаляємо значення попереднього вводу
			std::cout << "Введене не коректне значення. \n";			      //і вхідного буфера
			std::cout << "Введіть число ще раз. \n";			      //і вхідного буфера
		}
		else
		{
			return num;
		}
	}
}	

//функція в залежності від дискримінанта
//вираховує і виводить на друк рішення рівняння
//приймає дискримінант і два перших вхідних числа double
void CheckAndPrint (double discriminator, double a, double b)
{
    if (discriminator < 0)
    {
        std::cout << "Рівняння немає рішення (коренів). \n";
    }
    else if (discriminator == 0)
    {
        std::cout << "Рівняння має один корінь: \n";
        std::cout << "х1 = " << (-b+sqrt(discriminator))/(2*a) << "\n";
    }
    else if (discriminator > 0)
    {
        std::cout << "Рівняння має два корені: \n";
        std::cout << "х1 = " << (-b+sqrt(discriminator))/(2*a) << "\n";
        std::cout << "х2 = " << (-b-sqrt(discriminator))/(2*a) << "\n";
    }
}

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
	std::cout << "Програма вирішує квадратне рівняння. \n";
    std::cout << "Введіть число a: \n";
    a = get_number();
	std::cout << "Введіть число b: \n";
    b = get_number();
	std::cout << "Введіть число c: \n";
    c = get_number();

    double discriminator = pow (b,2)-4*a*c;
	
//  дискримінант для наглядності
//  std::cout << "-------------------- \n";
//	std::cout << "Дискримінант: " << D << "\n";

    CheckAndPrint (discriminator, a, b);
    return 0;
}

