//програма приймає значення кількості чисел що необхідно просумувати
//і значення які необхідно просумувати
//вивдодить введені значення і суму
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
			std::cin.clear(); //повертаємо cin в звичайний режим роботи
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
//повертає вектор з числами
void read_data( std::vector< double >& numbers, std::istream &stream = std::cin) {
    std::size_t pos{};
    std::string number_str;
    std::cout << "Введіть декілька цілих чисел ('|' для виходу) \n";
    
    for(;;) {
        stream >> number_str;
            if ("|" == number_str) {
                return;
            }
    
        try {
            //тут проблема з типом double
            //потрібно глянути як переводити string в double
            const double number {std::stod(number_str, &pos)};
            if (pos != number_str.size()) {
                throw std::invalid_argument(number_str);
            }
            numbers.push_back(number);
        }
        catch(std::invalid_argument const& ex) {
            std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
        }
        catch(std::out_of_range const& ex) {
            std::cout << "std::out_of_range::what(): " << ex.what() << '\n';
        }
    }
}

//функція підрахунку вказаної суми чисел
//приймає кількість чисел що сумуються і вектор з необхідними числами
//повертає суму чисел
double calculation( int number_for_sum, std::vector< double > numbers, std::vector< double >& real_numbers ) {
    double sum = 0;
    if( number_for_sum <= numbers.size() ) {
        for( int i = 0; i < number_for_sum; ++i) {
            sum += numbers[i];
        }
    }
    
    if( numbers.size() > 1 ) {
        for( int i = 0; i < numbers.size()-1; ++i ) {
            real_numbers.push_back( numbers[i]-numbers[i+1] );
        }
    }
    return sum; 
}

//Функція друку результатів роботи програми
//приймає кількість числел що сумуються, вектор чисел і значення суми цих чисел
void print_results( int number_for_sum, std::vector< double > numbers, double sum, std::vector< double > real_numbers ) 
{
    if( 0 > number_for_sum ) {
        std::cout << "Ви хочете просумувати від'ємну кількість чисел" << '\n';
    } 
    else if( 0 == number_for_sum ) {
        std::cout << "Ви хочете просумувати нульову кількість значень" << '\n';
    }
    else if( 1 == number_for_sum ) {
        std::cout << "Ви хочете просумувати лише одне значення" << '\n';
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

    switch( numbers.size() ) {
        case 0:
            std::cout << "Ви не ввели жодного дійсного числа." << '\n'; 
            break;
        case 1:
            std::cout << "Ви ввели одне дійсне число. " <<  
                "Цього недостатньо для визначення різниці дійсних чисел." << '\n'; 
            break;
        default: 
            std::cout << "Різниці між сусідніми введеними числами: " << '\n'; 
            for( double x : real_numbers) {
                std::cout << x << '\n';
            }
            break;
    }
}

//тестова функція
void test_data_one( std::vector< double >& numbers, std::vector< double >& real_numbers ) 
{
    int number_for_sum = 2;
    std::stringstream stream;
    stream << "4.5" << " " << "45r" << "\n" << "5.ee" << " " 
    << "6" << "\n" << "0.5" << " " << "|" << "\n";

    std::vector< double > test;
    read_data ( numbers, stream );
    test = numbers;
    double sum = calculation( number_for_sum, test, real_numbers );
    print_results( number_for_sum, test, sum, real_numbers );

    assertm( 3 == test.size(), "Numbers size 3 expected");
    assertm( 2 == real_numbers.size(), "Real_numbers size 2 expected");

    std::cout << "Test [" << __FUNCTION__ << "] PASSED\n";
}

int main()
{
    int number_for_sum = get_number();
    std::vector< double > numbers;
    std::vector< double > real_numbers;
    read_data( numbers );
//    для коректного запуску тестової функції закоментити рядки
//    151, 154, 159, 160  
//    test_data_one( numbers, real_numbers ); 

    double sum = calculation( number_for_sum, numbers, real_numbers );
    print_results( number_for_sum, numbers, sum, real_numbers );

	return 0;	
}
