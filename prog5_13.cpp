//програма приймає значення днів тижня і чисел
//вивдодить список днів тижня і відповідних введених чисел
//виводить суму чисел кожного дня та кількість некоретних вводів
#include <iostream>
#include <vector>
#include <sstream>

//функція вводу значень днів тижня і чисел
//повертає відповідні вектори
void read_data( std::vector<std::string>& days, std::vector<double>& numbers, 
                std::istream& stream = std::cin ) 
{
    std::cout << "Введіть день тижня та число: \n";
    std::cout << "Для виходу введіть 'NoName 0' \n";
    std::string line;
    while( std::getline( stream, line ) ) 
    {
        std::stringstream string_stream{ line };
//        std:: cout << "line :" << line << std::endl;

        std::string name;
        string_stream >> name;
        double number{ 0.0 };
        string_stream >> number;
        if ( string_stream.fail() )  //якщо попереднє введене значення не вдале
        {
			std::cout << "Введене не коректне значення, спробуйте знову. \n";
            continue;
        }
        if ("NoName" == name && 0 == number)
        {
            return;
        }
        
//        std::cout << "name :" << name << "  " << "nuber :" << number << std::endl;

        days.push_back( name );
        numbers.push_back( number );
    }
}

//функція сортування введених значень у віддповідні вектори чисел днів тижня, а також підрахунку кількості некоретних вводів
//повертає заповнені вектори днів тижня введеними числами, а також кількість некоретних вводів
void sort_input_numbers( const std::vector< std::string >& days, const std::vector< double >& numbers, std::vector< double >& monday,
                        std::vector< double >& tuesday, std::vector< double >& wednesday, std::vector< double >& thursday,
                        std::vector< double >& friday, std::vector< double >& saturday, std::vector< double >& sunday, int& rejected )
{
    for( int i = 0; i < numbers.size(); ++i )
    {
        if( days[i] == "Monday" || days[i] == "monday" || days[i] == "Mon" )
        {
            monday.push_back( numbers[i] );
        }
        else if( days[i] == "Tuesday" || days[i] == "tuesday" || days[i] == "Tue" )
        {
            tuesday.push_back( numbers[i] );
        }
        else if( days[i] == "Wednesday" || days[i] == "wednesday" || days[i] == "Wed" )
        {
            wednesday.push_back( numbers[i] );
        }
        else if( days[i] == "Thursday" || days[i] == "thursday" || days[i] == "Thu" )
        {
            thursday.push_back( numbers[i] );
        }
        else if( days[i] == "Friday" || days[i] == "friday" || days[i] == "Fri" )
        {
            friday.push_back( numbers[i] );
        }
        else if( days[i] == "Saturday" || days[i] == "saturday" || days[i] == "Sat" )
        {
            saturday.push_back( numbers[i] );
        }
        else if( days[i] == "Sunday" || days[i] == "sunday" || days[i] == "Sun" )
        {
            sunday.push_back( numbers[i] );
        }
        else
        {
            ++rejected;
        }
    }
}

//функція виводу на екран результатів вводу
//також підраховує і виводить на екран суму введених значень по кожному дню тижня
void print_results( const std::vector< std::string >& days, const std::vector< double >& numbers, std::vector< double >& monday,
                    std::vector< double >& tuesday, std::vector< double >& wednesday, std::vector< double >& thursday,
                    std::vector< double >& friday, std::vector< double >& saturday, std::vector< double >& sunday, int rejected )
{
    std::cout << "-------------------------- \n";
    double sum_mon = 0.0;
    double sum_tue = 0.0;
    double sum_wed = 0.0;
    double sum_thu = 0.0;
    double sum_fri = 0.0;
    double sum_sat = 0.0;
    double sum_sun = 0.0;
//    if( days.size() > 0 )
//    {
//        for ( int i = 0; i < days.size(); ++i )
//        {
//            std::cout << "День " << days[i] << '\t' << "число " << numbers[i] << '\n';
//        }
//    }
//    else
//    {
//        std::cout << "Не введено жодного коректного значення дня і числа" << '\n';
//    }
    if( monday.size() > 0 )
    {
        std::cout << "Числа Monday: " << '\n';
        for( int i = 0; i < monday.size(); ++i )
        {
            std::cout << monday[i] << '\n';
            sum_mon += monday[i];
        }
        std::cout << "Сума чисел Monday: " << sum_mon << '\n';
    }
    else
    {
        std::cout << "Monday не введено жодного коректного значення." << '\n';
    }
    if( tuesday.size() > 0 )
    {
        std::cout << "Числа Tuesday: " << '\n';
        for( int i = 0; i < tuesday.size(); ++i )
        {
            std::cout << tuesday[i] << '\n';
            sum_tue += tuesday[i];
        }
        std::cout << "Сума чисел Tuesday: " << sum_tue << '\n';
    }
    else
    {
        std::cout << "Tuesday не введено жодного коректного значення." << '\n';
    }
    if( wednesday.size() > 0 )
    {
        std::cout << "Числа Wednesday: " << '\n';
        for( int i = 0; i < wednesday.size(); ++i )
        {
            std::cout << wednesday[i] << '\n';
            sum_wed += wednesday[i];
        }
        std::cout << "Сума чисел Wednesday: " << sum_wed << '\n';
    }
    else
    {
        std::cout << "Wednesday не введено жодного коректного значення." << '\n';
    }
    if( thursday.size() > 0 )
    {
        std::cout << "Числа Thursday: " << '\n';
        for( int i = 0; i < thursday.size(); ++i )
        {
            std::cout << thursday[i] << '\n';
            sum_thu += thursday[i];
        }
        std::cout << "Сума чисел Thursday: " << sum_thu << '\n';
    }
    else
    {
        std::cout << "Thursday не введено жодного коректного значення." << '\n';
    }
    if( friday.size() > 0 )
    {
        std::cout << "Числа Friday: " << '\n';
        for( int i = 0; i < friday.size(); ++i )
        {
            std::cout << friday[i] << '\n';
            sum_fri += friday[i];
        }
        std::cout << "Сума чисел Friday: " << sum_fri << '\n';
    }
    else
    {
        std::cout << "Friday не введено жодного коректного значення." << '\n';
    }
    if( saturday.size() > 0 )
    {
        std::cout << "Числа Saturday: " << '\n';
        for( int i = 0; i < saturday.size(); ++i )
        {
            std::cout << saturday[i] << '\n';
            sum_sat += saturday[i];
        }
        std::cout << "Сума чисел Saturday: " << sum_sat << '\n';
    }
    else
    {
        std::cout << "Saturday не введено жодного коректного значення." << '\n';
    }
    if( sunday.size() > 0 )
    {
        std::cout << "Числа Sunday: " << '\n';
        for( int i = 0; i < sunday.size(); ++i )
        {
            std::cout << sunday[i] << '\n';
            sum_sun += sunday[i];
        }
        std::cout << "Сума чисел Sunday: " << sum_sun << '\n';
    }
    else
    {
        std::cout << "Sunday не введено жодного коректного значення." << '\n';
    }
    std::cout << "Кількість відхилених значень: " << rejected << '\n';
} 

int main()
{
    std::vector<std::string> days;
    std::vector<double> numbers;
    std::vector<double> monday;
    std::vector<double> tuesday;
    std::vector<double> wednesday;
    std::vector<double> thursday;
    std::vector<double> friday;
    std::vector<double> saturday;
    std::vector<double> sunday;
    int rejected = 0;
    
    read_data( days, numbers );
    sort_input_numbers( days, numbers, monday, tuesday, wednesday, thursday, friday, saturday, sunday, rejected );
    print_results( days, numbers, monday, tuesday, wednesday, thursday, friday, saturday, sunday, rejected );

	return 0;	
}
