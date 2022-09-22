//гра 'бики і корови'
#include <iostream>
#include <vector>
#include <stdlib.h>	//для виклику функції rand()
#include <time.h>	//для виклику функції time()

//функція генерує випадкове число у визначеному діапазоні
//приймає мінімальне і максимальне число діапазону
//повертає випадкове ціле число з вибраного діапазону
int get_random_number( int min_number, int max_number )
{
	//установка генератора випадкових числел (srand())
	//тобто задається число, на основі якого вираховується послідовність випадкових чисел з допомогою rand()
	//число задається функцією time(), NULL - це число мілісекунд, які
	//пройшли від 01.01.1970 року 
//	srand(time(NULL));	
	
    int rand_number = min_number + rand() % (max_number - min_number + 1);
	return rand_number;
}

//функція введення цілого числа з необхідними обмеженнями
//повертає ціле число
//запобігає некоректному вводу числа
int get_number( std::istream &stream = std::cin ) 
{
    while (true)
    {
        std::string number_str;
        stream >> number_str;
        try 
        {
            const int number{ std::stoi( number_str ) };
            if( 1 != number_str.size() ) 
            {
                throw std::invalid_argument( "Out of range 0-9" );
            }
            if( 0 > number || 9 < number )
            {
                throw std::invalid_argument( "Out of range 0-9" );
            }
           return number;
        }
        catch(std::invalid_argument const& ex) {
            std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
            std::cout << "Введене не коректне значення, спробуйте знову. \n";
        }
        catch(std::out_of_range const& ex) {
            std::cout << "std::out_of_range::what(): " << ex.what() << '\n';
            std::cout << "Введене не коректне значення, спробуйте знову. \n";
        }        
    }
}

//функція отмимання вектора з 4 випадкових чисел від 0 до 9
//які не повторюються
void get_mystery_numbers( std::vector< int >& mystery_numbers )
{
	srand(time(NULL));	
    int vector_checking = 1;
    for( int i = 0; i < 4; ++i )
    {
        mystery_numbers[ i ] = get_random_number( 0,9 );
begin_for_j:
        for( int j = 0; j < vector_checking; ++j )
        {
            if( i != j )
            {   
                if( mystery_numbers[ i ] == mystery_numbers[ j ] )
                {
                    mystery_numbers[ i ] = get_random_number( 0,9 );
                    goto begin_for_j;
                }
            }
        }
        ++vector_checking;
    }
}

void get_mystery_numbers_2( std::vector< int >& mystery_numbers )
{
    srand(time(NULL));
    for ( size_t index = 0u; index < mystery_numbers.size(); )
    {
        uint8_t mystery_number = get_random_number( 0,9 );
        bool is_unique = true;
        for( auto number : mystery_numbers ) 
        {
            if( number == mystery_number ) 
            {
                is_unique = false;
                break;
            }
        }
        if( is_unique ) 
        {
            mystery_numbers[ index ] = mystery_number;
            ++index;
        }
    }
}

//функція вводу вектора з 4 чисел від 0 до 9 які не повторюються
void get_answer_numbers( std::vector< int >& answer_numbers )
{
    int vector_checking = 1;
    for( int i = 0; i < 4; ++i )
    {
        std::cout << "Введіть число #" << i + 1 << "\n";
        answer_numbers[ i ] = get_number();
begin_for_j:
        for( int j = 0; j < vector_checking; ++j )
        {
            if( i != j )
            {   
                if( answer_numbers[ i ] == answer_numbers[ j ] )
                {
                    std::cout << "Введене число #" << i + 1 << " співпадає з введеним числом #" << j + 1 << "\n";
                    std::cout << "Введіть число #" << i + 1 << " повторно:\n";
                    answer_numbers[ i ] = get_number( );
                    goto begin_for_j;
                }
            }
        }
        ++vector_checking;
    }
}

void get_answer_numbers_2( std::vector< int >& answer_numbers )
{
    answer_numbers.assign(4,255);
    std::cout << '\n';
    for ( size_t index = 0u; index < answer_numbers.size(); )
    {
        std::cout << "Введіть число #" << index + 1 << "\n";
        uint8_t answer_number = get_number( );
        bool is_unique = true;
        for( auto number : answer_numbers ) 
        {
            if( number == answer_number ) 
            {
                std::cout << "Введене число #" << index + 1 << " співпадає з раніше введеним числом." << "\n";
                std::cout << "Введіть число #" << index + 1 << " повторно:\n";
                is_unique = false;
                break;
            }
        }
        if( is_unique ) 
        {
            answer_numbers[ index ] = answer_number;
            ++index;
        }
    }
}

//функція порівняння вертора випадкових чисел і введеного вектора
//і визначнення співпадіння чисел і їх позицій відповідно до умов гри
void compare_numbers( const std::vector< int >& mystery_numbers, const std::vector< int >& answer_numbers, int& cows, int& bulls )
{
    bulls = 0;
    cows = 0;
    for( size_t i = 0u; i < mystery_numbers.size(); ++i )
    {
        if( mystery_numbers[i] == answer_numbers[i] )
        {
            ++bulls;
        }
    }

    for( size_t i = 0u; i < mystery_numbers.size(); ++i )
    {
        for( size_t j = 0u; j < mystery_numbers.size(); ++j )
        {
            if( mystery_numbers[i] == answer_numbers[j] )
            {
                ++cows;
            }
        }    
    }
    cows = cows - bulls;
}

//функція виводу результатів порівняння
void print_results( const std::vector< int >& mystery_numbers, const std::vector< int >& answer_numbers, int cows, int bulls )
{
    std::cout << "Загадані числа: \n";
    for( auto x : mystery_numbers ) 
    {
       std::cout << x << '\t';
    }
    std::cout << '\n';
    std::cout << "Введені числа: \n";
    for( auto y : answer_numbers ) 
    {
        std::cout << y << '\t';
    }
    std::cout << '\n';
    std::cout << "Результати: \n";
    std::cout << "Бички: " << bulls << '\n';
    std::cout << "Корови: " << cows << '\n';
}


int main ()
{
    std::cout << "Вас вітає гра 'Бички і корови'.\n";
    std::vector< int > mystery_numbers( 4,-1 );
    std::vector< int > answer_numbers( 4,-1 );
    std::cout << '\n';
    int cows = 0;
    int bulls = 0;
    get_mystery_numbers_2( mystery_numbers );
    for(;;)
    {
        if( bulls == 4 )
        {
            std::cout << "Загадані числа: \n";
            for( auto x : mystery_numbers ) 
            {
                std::cout << x << '\t';
            }
            std::cout << '\n';
            std::cout << "Вітаємо, ви відгадали всі числа на своїх місцях і перемогли! \n";
            break;
        }
        get_answer_numbers_2( answer_numbers );
        compare_numbers( mystery_numbers, answer_numbers, cows, bulls );
        print_results( mystery_numbers, answer_numbers, cows, bulls );
    }
	return 0;
}



