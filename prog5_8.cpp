//програма приймає значення кількості чисел що необхідно просумувати
//і значення які необхідно просумувати
//вивдодить введені значення і суму
//програма не допрацьована до кінця, тому присутні частини коду, що на разі не використовуюється
#include <iostream>
#include <vector>
#include <cassert> //підключає assertm
#include <sstream> //підключає std::stringstream
#include <string> //викликає функцію stoi

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

//функція введення кількості чисел, що необхідно просумувати
//повертає ціле число
//запобігає некоректному вводу числа
int get_number() 
{
	while (true)
	{
		std::cout << "Введіть кількість значень що додаються: \n";
		int number = 0;
       		std::cin >> number;
            std::cin.ignore( 32767, '\n');
		if (std::cin.fail())	//якщо попереднє введене значення не вдале
		{
			std::cin.clear(); //повертаємо cin в звичайний режи роботи
			std::cin.ignore(32767, '\n'); //і видаляємо значення попереднього вводу
			std::cout << "Введене не коректне значення, спробуйте знову. \n";			      //і вхідного буфера
		}
		else
		{
			return number;
		}
	}
}	

//функція вводу чисел
//приймає потік вхідних чисел
//повертає вектор з цілими числами
void read_data( std::vector< int >& numbers, std::istream &stream = std::cin)
{
    std::string num;
    std::string symbol;
    std::string temp;
    std::string inappropriate_symbols;
//    std::string temp2;
//    int count = 0;
//    std::stringstream ss;
    int number = 0;
    std::cout << "Введіть декілька цілих чисел ('|' для виходу) \n";
    std::string line;
//    std::getline( stream, line );

    while ( std::getline(stream, line ) )
    {
        std::stringstream string_stream{ line };
//            symbol = string_stream.peek();
//            std::cout << symbol << '\n';
//            if( stoi( symbol ) ) {
//                number = stoi ( symbol );
//            }
//            std::cout << number << '\n';

        //цикл рахує кількість символі
//        while( string_stream >> temp ) {
//            if( "|" == temp) { break; }
//           ++count;
//    //        number = stoi( temp );
//    //        numbers.push_back( number );
//            ss << temp + " ";
//        }
        
//        while( "|" != symbol ) {
        for( int i = 0; i < line.size(); ++i) {            
            symbol = string_stream.peek();
//            std::cout << symbol << '\n';
            
            try {
                stoi( symbol );
                num += string_stream.get(); 
                std::cout << num << '\n';
            }
            catch( std::invalid_argument ex) {
                std::cout << symbol << " invalid_argument " << ex.what() << '\n';
                temp = string_stream.get(); //костиль
                if( " " != temp && "|" != temp ) { inappropriate_symbols += temp; }
                std::cout << temp << '\n';
//                symbol = string_stream.peek();
//                while( " " != symbol || "|" != symbol ) {
//                    temp = string_stream.get();
//                    symbol = string_stream.peek();
//                }
//               num = {};
            }

//            try { 
//                stoi( num ); 
            
            if( " " == symbol || "\n" == symbol || "|" == symbol ) { 
                number = stoi( num );
                std::cout << "-----------------\n";
                std::cout << number << '\n';
                numbers.push_back( number );
//                temp = string_stream.get();
                num = {};
            }
//            }
//            catch( std::out_of_range ) {
//                std::cout << num << " out_of_range" << '\n';
//                temp2 = num;
//            }
            if( "|" == symbol ) { break; }
        }        


//        std::cout << string_stream.str() << '\n';
//        std::cout << ss.str() << '\n';

//        while( ss >> number ) {
//            numbers.push_back( number );
//        }
//    std::cout << "-----------------\n";
    
//        for( int i = numbers.size(); i < count; ++i ) {
//            ss >> number;
//            if( ss.fail() ) {
//                std::cout << "Fail \n"; 
//                ss.setstate(std::ios_base::goodbit);
//                continue; 
//            }
//          else { numbers.push_back( number ); 
//            }
//        }
        
//        if( string_stream.fail( ) ) //якщо попереднє введене значення не вдале
//        {
//            std::cout << "Введене не коректне значення, спробуйте знову. \n";
//            continue;
//        }

//        if( "|" == temp) { break; }
        if( "|" == symbol) { break; }
    }

    if( inappropriate_symbols.size() != 0 ) {
        std::cout << "Введені значення: " << inappropriate_symbols << " проігноровані, оскільки не є числами" << '\n';
    }
//    std::cout << "Число: " << temp2 << " завелике" << '\n';
//    return numbers;
}

//функція підрахунку вказаної суми чисел
//приймає кількість чисел що сумуються і вектор з необхідними числами
//повертає суму чисел
int calculation( int number_for_sum, std::vector< int > numbers ) {
    int sum = 0;
    if( number_for_sum <= numbers.size() ) {
        for( int i = 0; i < number_for_sum; ++i) {
            sum += numbers[i];
        }
    }
    return sum; 
}

//Функція друку результатів роботи програми
//приймає кількість числел що сумуються, вектор чисел і значення суми цих чисел
void print_results( int number_for_sum, std::vector< int > numbers, int sum ) 
{
    if( 0 > number_for_sum ) {
        std::cout << "Ви хочете просумувати від'ємну кількість чисел" << '\n';
    } 
    else if( 0 == number_for_sum ) {
        std::cout << "Ви хочете просумувати нульову кількість значень" << '\n';
    }
    else if( numbers.size() < number_for_sum ) {
        std::cout << "Ви хочете просумувати більше значень, ніж введено" << '\n';
    }
    else {
        std::cout << "Сума перших " << number_for_sum << " чисел ( "; 
        for( int i = 0; i < number_for_sum; ++i) {
            std::cout << numbers[i] << " ";
        }
        std::cout << ") дорівнює " << sum << '\n'; 
    }
}

//тестова функція
//з попередньої програми
void test_data_one( ) 
{
//    std::stringstream stream;
//    stream << "dd" << " " << "1" << "\n" << "ee" << " " 
//    << "3" << "\n" << "NoName" << " " << "0" << "\n";
//
//    std::pair<std::vector<std::string>,std::vector<double>> test = read_data (stream);
//    print_results(test.first, test.second);
//
//    assertm( 2 == test.first.size(), "Names size 2 expected");
//    assertm( 2 == test.second.size(), "Scores size 2 expected");
//
//   std::cout << "Test [" << __FUNCTION__ << "] PASSED\n";
}

int main()
{
//    test_data_one(); 
    
    int number_for_sum = get_number();
    std::vector< int > numbers;
    read_data( numbers );

    std::cout << number_for_sum << '\n';
    for( int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << '\n';
    }
//    std::cout << "-----------------\n";
    
    int sum = calculation( number_for_sum, numbers );
    print_results( number_for_sum, numbers, sum );

	return 0;	
}
