//програма приймає значення імен і рахунку
//перевіряє на повторюваність імен 
//вивдодить список введених імен і рахунків
#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <limits>

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

//Функція друку результатів роботи програми
//приймає вектори імен і рахунків
void print_results(std::vector<std::string> names, std::vector<int> scores) 
{
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

    for (int i = 0; i < names.size(); ++i)
    {
        std::cout << names[i] << "\t" << scores[i] << "\n";
    }
}

//функція для виводу значення імен, що мають введений рахунок
//приймає введений рахунок і вектори раніше введених імен і рахунків
void print_name (int number, std::vector<std::string> names, std::vector<int> scores)
{
    int count = 0;
    for (int i = 0; i < scores.size(); ++i)
    {
        if (number == scores[i])        
        {
            std::cout << names[i] << "\t" << scores[i] << "\n";
            ++count;
        }
    }        
    if (count == 0)
    {    
        std::cout << "Немає студентів з таким рахунком. \n";
    }
}

//тестова функція
//приймає 1 введене значення імені  і рахунку
//тому що немає окремої функції прийому значень
//тому що не розібрався як з неї повернути 2 вектори
void test_data_one (std::vector<std::string> names, std::vector<int> scores) 
{
//    names.clear(); //не очищаю тому що 1 введення потрібно провести з main
//    scores.clear();
    std::string name = " ";
    int number = 1;

    std::stringstream stream;
    stream << "dd" << " " << "1" << "\n" << "ee" << " "
    << "3" << "\n" << "NoName" << " " << "0" << "\n";
        stream >> name >> number; //чомусь не виводить з потоку 'ee' i '3', можливо мало змінних?
        names.push_back(name);
        scores.push_back(number);
//    read_data (names, scores, stream);

    print_results(names, scores);

    assertm( 2 == names.size(), "Names size 2 expected");
    assertm( 2 == scores.size(), "Scores size 2 expected");

    std::cout << "Test [" << __FUNCTION__ << "] PASSED\n";
}

int main()
{
   
    std::string name = " ";
    std::string line;
    int number = 1;
    std::stringstream stream;
    std::vector<std::string> names;
    std::vector<int> scores;

    for (int i = 0; i < std::numeric_limits<double>::max(); ++i)
//    while (std::getline(stream, line))
    {
        std::cout << "Введіть ім'я та рахунок: \n";
        std::cout << "Для виходу введіть 'NoName 0' \n";
        std::getline(std::cin, line);
        stream << line << std::endl;  
        stream >> name >> number;        
        if (stream.fail())  //якщо попереднє введене значення не вдале
        {
			std::cout << "Введене не коректне значення, спробуйте знову. \n";
            stream.clear();
            stream.str(std::string());
            continue;
        }
        if ("NoName" == name && 0 == number)
        {
            break;
        }
        names.push_back(name);
        scores.push_back(number);
    }
//зняти слеші щоб працювала тестова функція
//для тесту ввести одне значення імені і рахунку потім 'NoName 0'
//    test_data_one (names, scores); 
    print_results(names, scores);

    std::cout << "Введіть рахунок для виводу імен, що його мають: \n";
    std::cin >> number;
    print_name(number, names, scores);
    return 0;	
}
