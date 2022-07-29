//програма вирішує квадратне рівняння
//ax2(квадрат) + bx + c = 0;

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

//функція вираховує дискримінант
//приймає три числа double
//повертає дискримінант double
double get_discriminator(double a, double b, double c)
{
    double D = pow (b,2)-4*a*c;
    return D;
}


int main()
{
    double a,b,c = 0;
	std::cout << "Програма вирішує квадратне рівняння. \n";
    std::cout << "Введіть число a: \n";
    a = get_number();
	std::cout << "Введіть число b: \n";
    b = get_number();
	std::cout << "Введіть число c: \n";
    c = get_number();

    double D = get_discriminator(a,b,c);
	
//  дискримінант для наглядності
//  std::cout << "-------------------- \n";
//	std::cout << "Дискримінант: " << D << "\n";
    
    if (D < 0)
    {
	    std::cout << "Рівняння немає рішення (коренів). \n";
    }
    else if (D == 0)
    {
	    std::cout << "Рівняння має один корінь: \n";
	    std::cout << "х1 = " << (-b+sqrt(D))/(2*a) << "\n";
    }
    else if (D > 0)
    {
	    std::cout << "Рівняння має два корені: \n";
	    std::cout << "х1 = " << (-b+sqrt(D))/(2*a) << "\n";
	    std::cout << "х2 = " << (-b-sqrt(D))/(2*a) << "\n";
    }

    return 0;
}

