//програма приймає значення імен і рахунку
//перевіряє на повторюваність імен 
//вивдодить список введених імен і рахунків
#include <iostream>
#include <vector>
#include <cassert> //підключає assertm
#include <sstream> //підключає std::stringstream
#include <utility> //підключає std::pair

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

//Функція друку результатів роботи програми
//приймає вектори імен і рахунків
void print_results (std::vector<std::string> names, std::vector<double> scores) 
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

std::pair <std::vector <std::string>, std::vector<double>> read_data (std::istream &stream = std::cin)
{
    std::vector< std::string > names;
    std::vector< double > scores;
    std::cout << "Введіть ім'я та рахунок: \n";
    std::cout << "Для виходу введіть 'NoName 0' \n";
    std::string line;
    while ( std::getline(stream, line ) )
    {
        std::stringstream string_stream{ line };
        std::string name;
        string_stream >> name;
        double number{ 0.0 };
        string_stream >> number;
        if ( string_stream.fail( ) ) //якщо попереднє введене значення не вдале
        {
            std::cout << "Введене не коректне значення, спробуйте знову. \n";
            continue;
        }
        if ( "NoName" == name && 0 == number )
        {
            break;
        }

        std::cout << "name :" << name << "  "
              << "nuber :" << number << std::endl;
        names.push_back( name );
        scores.push_back( number );
        }
    return { names, scores };
}

//тестова функція
//імітує введення двох імен і рахунків та закінчення вводу
//тестує чи правильно працює функція read_data() в частині розміру 
//масиву введених значень
void test_data_one( ) 
{
    std::stringstream stream;
    stream << "dd" << " " << "1" << "\n" << "ee" << " " 
    << "3" << "\n" << "NoName" << " " << "0" << "\n";

    std::pair<std::vector<std::string>,std::vector<double>> test = read_data (stream);
    print_results(test.first, test.second);

    assertm( 2 == test.first.size(), "Names size 2 expected");
    assertm( 2 == test.second.size(), "Scores size 2 expected");

    std::cout << "Test [" << __FUNCTION__ << "] PASSED\n";
}

int main()
{
    std::string name = " ";
    std::string line;
    double number = 1;
    std::stringstream stream;
    std::vector<std::string> names;
    std::vector<double> scores;

//зняти слеші з test_data_one () і заслешити дві наступні строчки read_data() i print_rezult()
//щоб працювала тестова функція
//    test_data_one (); 

    //std::pair може зберігати два різні вектори в одному (об'єкті)    
    std::pair<std::vector<std::string>,std::vector<double>> result = read_data();
    print_results(result.first, result.second);

	return 0;	
}
