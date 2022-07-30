//програма приймає значення імен і рахунку
//перевіряє на повторюваність імен 
//вивдодить список введених імен і рахунків
#include <iostream>
#include <vector>

//функія введенння імені
//видає строкове значення введеного імені
std::string GetName() 
{
    std::cout << "Введіть ім'я та рахунок: \n";
    std::cout << "Для виходу введіть 'NoName 0' \n";
	std::string name;
	std::cin >> name;

	return name;
}

//функція введення числа
//повертає десяткове число
//запобігає некоректному вводу числа
double GetNumber() 
{
	while (true)
	{
		double num = 0;
       	std::cin >> num;
		if (std::cin.fail())	//якщо попереднє введене значення не вдале
		{
			std::cin.clear(); //повертаємо cin в звичайний режим роботи
			std::cin.ignore(32767, '\n'); //і видаляємо значення попереднього вводу i вхідного буфера
			std::cout << "Введене не коректне значення. \n";			      
			std::cout << "Введіть значення повторно. \n";			      
		}
		else
		{
			return num;
		}
	}
}	

int main()
{
    std::string name = " ";
    double number = 1;
    std::vector<std::string> names;
    std::vector<double> scores;

    while (name != "NoName" || number != 0)
    {
        name = GetName();
        number = GetNumber();
        names.push_back(name);
        scores.push_back(number);
    }

    std::cout << "-------------------------- \n";
    for (int i = 0; i < names.size(); ++i)
    {
        for (int j = i+1; j < names.size(); ++j)
        {
            if (names[i] == names[j])
            {
                std::cout << "Ім'я " << names[i] << " повторюється \n";
            }
        }     
    } 
    std::cout << "-------------------------- \n";

    for (int i = 0; i < names.size()-1; ++i)
    {
        std::cout << names[i] << "\t" << scores[i] << "\n";
    }
	return 0;	
}
