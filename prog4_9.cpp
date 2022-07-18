//програма приймає значення кількості і одиниць виміру
//вивдодить найменше і найбільше значення в процесі вводу одиниць
//перетворює введені відстані в метри
//виводить відсотрований список введених відстаней в метрах,
//загальну довжину, кількість введених значень найменше і найбільше
//введене значення
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>


//функія введенння одиниць виміру
//видає строкове значення введеного елементу виміру
std::string input_unit() 
{
	std::string i_unit = "";
	std::cin >> i_unit;

	return i_unit;
}

//функція введення кількості одиниць виміру
//повертає десяткове число відстані
//запобігає некоректному вводу числа
double input_number() 
{
	while (true)
	{
		std::cout << "Введіть відстань і її одиниці виміру (cm, m, in, ft): \nабо для виходу введіть '1|': \n";
		double i_number = 0;
       		std::cin >> i_number;
		if (std::cin.fail())	//якщо попереднє введене значення не вдале
		{
			std::cin.clear(); //повертаємо cin в звичайний режи роботи
			std::cin.ignore(32767, '\n'); //і видаляємо значення попереднього вводу
			std::cout << "Введене не коректне значення відстані. \n";			      //і вхідного буфера
		}
		else
		{
			return i_number;
		}
	}
}	

//функція порівняння одиниць виміру.
//приймає введені раніше одиниці виміру.
//перевіряє чи збігаються введені одиниці виміру
//з допустими за відповідними умовами.
//видає true чи false.
bool compare_units (std::string unit) 
{

	bool i_compare = false;

	const std::vector<std::string> unit_permiss = {"cm","m","in","ft"}; //вектор з допустимими одиницями виміру
	for (const std::string unit_elem : unit_permiss)
	{
		if (unit == unit_elem)
		{
			i_compare = true;
		}
	}
	return i_compare;
}

//функція для перетворення різних одиниць виміру в метри.
//приймає введені раніше відстань та одиниці виміру.
//перетворює введені відстані в метри.
//видає десяткове число відстані в метрах.
double transformation (double number, std::string unit) 
{
	double i_meters = 0;
	if (unit == "cm")
	{
		i_meters = number/100;
	}
	else if (unit == "in")
	{
		i_meters = number*2.54/100;	
	}
	else if (unit == "ft")
	{
		i_meters = number*12*2.54/100;
	}
	else if (unit == "m")
	{
		i_meters = number;
	}	
	return i_meters;
}

int main()
{
	double number = 0;	//для введених чисел
	std::string unit = "";	//для введених одиниць
	double min_number = 0;
	double max_number = 0;
	std::string min_unit = " ";
	std::string max_unit = " ";
	double min = std::numeric_limits<double>::max(); //присвоюємо min найбільше з можливих чисел double
	double max = std::numeric_limits<double>::lowest();//присвоюємо max найменше з можливих числел double
	bool compare = false;//для веревірки введених одиниць виміру
	int all_amount = 0; //для загальної кількості значень
	double meters = 0;	//для перетворених відстаней
	double sum_in_meters = 0; // загальна відстань
	std::vector<double> all_meters; // вектор для перетворени значень
	for (int i = 0; i < std::numeric_limits<double>::max(); ++i) //цикл вводу значень
	{
		number = input_number();
		unit = input_unit();

		if (unit == "|") //вихід з циклу
		{
			break;
		}	
		compare = compare_units(unit);
			
		if (number < 0) //перевірка на від'ємну відстань
		{
			std::cout << "Відстань не може бути від'ємною.\n";
		}
		else if (!compare) //перевірка на допустимі значення одиниць виміру
		{
			std::cout << "'" << unit << "' є не допустимою одиницею виміру.\n";
		}
		else //прийом значень
		{
			++all_amount;
			meters = transformation(number, unit);
			sum_in_meters += meters;
			all_meters.push_back(meters);

			if (meters <= min)//перше введене число буде в любому випадку найменше,
				      //тому що воно завжди менше ніж найбільше число з можливих
			{	
				std::cout << number << " " << unit << " найменше серед введених чисел\n";
				min = meters;
				min_number = number;
				min_unit = unit;
			}
			else if (meters >= max)//якщо ми введемо більше число за раніше введене
				   //воно автоматично буде найбільше
				   //так як воно завжди більше за найменше число з усіх можливих
			{
				std::cout << number << " " << unit << " найбільше серед введених чисел\n";
				max = meters;
				max_number = number;
				max_unit = unit;
			}
			else
			{
				std::cout << number << " " << unit << "\n";
			}
		}
	}
	
	std::sort(all_meters.begin(), all_meters.end()); //сортуємо масив з метрами
	std::cout << "Всі введені відстані відсортовані по зростанню і переведені в метри:\n";
	for (int j = 0; j < all_meters.size(); ++j)
	{
		std::cout << all_meters[j] << " m.\n";
	}
	if (all_amount == 0)
	{
		std::cout << "Не введено жодного значення відстані. " << "\n";
	}
	else if (all_amount == 1)
	{
		std::cout << "Максимальне і мінімальне значення відстані однакові: " << min_number << " " << min_unit << "\n";
		std::cout << "Кількість введених значень: " << all_amount << "\n";
		std::cout << "Загальна відстань: " << sum_in_meters << " метрів.\n";
	}
	else
	{
		std::cout << "Найменше введене значення: " << min_number << " " << min_unit << "\n";
		std::cout << "Найбільше введене значення: " << max_number << " " << max_unit << "\n";
		std::cout << "Кількість введених значень: " << all_amount << "\n";
		std::cout << "Загальна відстань: " << sum_in_meters << " метрів.\n";
	}
	return 0;	
}
