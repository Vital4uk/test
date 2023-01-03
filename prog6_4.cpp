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

//class Name_value
//{
//public:
//    std::string v_name;        // what name
//    double value;            // for numbers: a value 
//    Name_value( std::string name, double number )     // make a Token from a string and a double
//        :v_name( name ), value( number ) { }
//};

struct Name_value
{
    std::string m_name;
    double m_value;
};

std::vector< Name_value > read_data( std::istream &stream = std::cin )
{
    std::vector< Name_value > names_scores;
//    std::vector< double > scores;
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
        if ( string_stream.fail() ) //якщо попереднє введене значення не вдале
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
        names_scores.emplace_back( name, number );
//        names_scores.push_back( name, number );
//        names_scores.value.push_back( number );
    }
    return names_scores;
}

//Функція друку результатів роботи програми
//приймає вектори імен і рахунків
void print_results( std::vector< Name_value > names_scores ) 
{
//    std::cout << "-------------------------- \n";
//    for( int i = 0; i < names_scores.size(); ++i )
//    {
//        for( int j = i + 1; j < names_scores.size(); ++j )
//        {
//            if( names_scores.v_name[i] == names_scores.v_name[j] )
//            {
//                std::cout << "Ім'я " << names_scores.v_name[i] << " повторюється \n";
//            }
//        }
//    }
//    std::cout << "-------------------------- \n";
    for ( auto&& score : names_scores )
    {
        std::cout << score.m_name << "\n";
    }

//    for( int i = 0; i < names_scores.size(); ++i )
//    {
//        std::cout << names_scores.name[i] << "\t" << names_scores.value[i] << "\n";
//        std::cout << names_scores[i] <<  "\n";
//    }
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

    std::vector< Name_value > test = read_data( stream );
    print_results( test );

    assertm( 2 == test.size(), "size 2 expected" );
//    assertm( 2 == test.value.size(), "Scores size 2 expected");

    std::cout << "Test [" << __FUNCTION__ << "] PASSED\n";
}

int main()
{

//зняти слеші з test_data_one () і заслешити дві наступні строчки read_data() i print_rezult()
//щоб працювала тестова функція
   test_data_one(); 

    //std::pair може зберігати два різні вектори в одному (об'єкті)    
//    std::pair<std::vector<std::string>,std::vector<double>> result = read_data();
//    print_results(result.first, result.second);

	return 0;	
}
