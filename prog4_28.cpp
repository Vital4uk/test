//програма приймає значення імен і рахунку
//перевіряє на повторюваність імен 
//вивдодить список введених імен і рахунків
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

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


std::string get_name_stream(std::istream& input_stream ) 
{
    std::cout << "Введіть ім'я та рахунок: \n";
    std::cout << "Для виходу введіть 'NoName 0' \n";
	std::string name;
	input_stream >> name;

	return name;
}

void print_results(std::vector<std::string>& names, std::vector<double>& scores) {
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

double get_number_stream(std::istream& input_stream ) 
{
	while (true)
	{
		std::cout << "Введіть число: \n";
		double number = 0.0;
       	input_stream >> number;
		if (input_stream.fail())	//якщо попереднє введене значення не вдале
		{
			input_stream.clear(); //повертаємо cin в звичайний режи роботи
			input_stream.ignore(32767, '\n'); //і видаляємо значення попереднього вводу
			std::cout << "Введене не коректне значення, спробуйте знову. \n";			      //і вхідного буфера
		}
		else
		{
			return number;
		}
	}
}	

void read_data (std::vector<std::string>& names, std::vector<double>& scores, 
                std::istream& stream = std::cin) {
    std::cout << "Введіть ім'я та рахунок: \n";
    std::cout << "Для виходу введіть 'NoName 0' \n";
    std::string line;
    while (std::getline(stream, line)) {
        std::stringstream string_stream {line};
        std:: cout << "line :" << line << std::endl;

        std::string name;
        string_stream >> name;
        double number {0.0};
        string_stream >> number;
        if (string_stream.fail())  //якщо попереднє введене значення не вдале
        {
			std::cout << "Введене не коректне значення, спробуйте знову. \n";
            continue;
        }
        if ("NoName" == name && 0 == number)
        {
            return;
        }
        
        std::cout << "name :" << name << "  " << "nuber :" << number << std::endl;

        names.push_back(name);
        scores.push_back(number);
    }
}


void test_data_one(std::vector<std::string>& names, std::vector<double>& scores ) {

    names.clear();
    scores.clear();

    std::stringstream stream;
    stream << "dd" << " " << "1" << "\n" << "ee" << " " 
    << "3" << "\n" << "NoName" << " " << "0" << "\n";
    read_data (names, scores, stream);

    print_results(names, scores);

    assertm( 2 == names.size(), "Names size 2 expected");
    assertm( 2 == scores.size(), "Scores size 2 expected");

    std::cout << "Test [" << __FUNCTION__ << "] PASSED\n";
}

int main()
{
    std::vector<std::string> names;
    std::vector<double> scores;

    read_data (names, scores);
    // test_data_one(names, scores); //запускає тестову функцію


	return 0;	
}
