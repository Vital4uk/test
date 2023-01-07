//програма приймає значення імен і рахунку
//перевіряє на повторюваність імен 
//вивдодить список введених імен і рахунків
#include <iostream>
#include <vector>
#include <cassert> //підключає assertm
#include <sstream> //підключає std::stringstream

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Name_value
{
public:
    std::string m_name;
    double m_value;
};

//функція вводу значень імені та рахунку
void read_data( std::vector< Name_value >& names_scores, std::istream &stream = std::cin )
{
    std::cout << "Введіть ім'я та рахунок: \n";
    std::cout << "Для виходу введіть 'NoName 0' \n";
    std::string line;
    Name_value temp;
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

        temp.m_name = name;
        temp.m_value = number;
        names_scores.push_back( temp );
    }
}

//функція порівнює введені імена на повторюваність
void compare( std::vector< Name_value > names_scores )
{
    for( size_t i = 0u; i < names_scores.size(); ++i )
    {
        for( size_t j = i + 1; j < names_scores.size(); ++j )
        {
            if( names_scores[i].m_name == names_scores[j].m_name )
            {
                std::cout << "Ім'я " << names_scores[i].m_name << " повторюється \n";
            }
        }
    }
}

//Функція друку результатів роботи програми
void print_results( std::vector< Name_value > names_scores ) 
{
    std::cout << "-------------------------- \n";

    for( size_t i = 0u; i < names_scores.size(); ++i)
    {
        std::cout << names_scores[i].m_name << " " << names_scores[i].m_value << std::endl;
    }
}

//тестова функція
//імітує введення двох імен і рахунків та закінчення вводу
//тестує чи правильно працює функція read_data() в частині розміру 
//масиву введених значень

void test_data_one( std::vector< Name_value > names_scores ) 
{
    std::stringstream stream;
    stream << "dd" << " " << "1" << "\n" << "ee" << " " 
    << "3" << "\n" << "dd" << " " << "1" << "\n" << "NoName" << " " << "0" << "\n";

    std::vector< Name_value > test( 3 );
    
    read_data( names_scores, stream );
    
    for( size_t i = 0u; i < names_scores.size(); ++i)
    {
        test[i].m_name = names_scores[i].m_name;
        test[i].m_value = names_scores[i].m_value;
    }
    
    compare( test );
    print_results( test );
    
    assertm( 3 == test.size(), "size 3 expected" );

    std::cout << "Test [" << __FUNCTION__ << "] PASSED\n";
}

int main()
{
    std::vector< Name_value > names_scores;
//    read_data( names_scores );
//    compare( names_scores );   
//    print_results( names_scores );  

//зняти слеші з test_data_one () і заслешити функції read_data(), compare() i print_results()
//щоб працювала тестова функція
    test_data_one( names_scores ); 

	return 0;	
}
