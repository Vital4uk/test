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
//        std::cout << "i = " << i << '\n';
        mystery_numbers[ i ] = get_random_number( 0,9 );
//        std::cout << "m_n[ " << i << " ] = " << mystery_numbers[ i ] << '\n';
begin_for_j:
        for( int j = 0; j < vector_checking; ++j )
        {
//            std::cout << "j begin = " << j << '\n';
            if( i != j )
            {   
                if( mystery_numbers[ i ] == mystery_numbers[ j ] )
                {
                    mystery_numbers[ i ] = get_random_number( 0,9 );
//                    std::cout << "m_n[ " << i << " ] = " << mystery_numbers[ i ] << '\n';
//                    j = 0;
                    goto begin_for_j;
//                    std::cout << "j after0 = " << j << '\n';
                }
            }
//            std::cout << "j end = " << j << '\n';
//            std::cout << "---------------------- " << '\n';
        }
        ++vector_checking;
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

//функція порівняння вертора випадкових чисел і введеного вектора
//і визначнення співпадіння чисел і їх позицій відповідно до умов гри
void compare_numbers( std::vector< int >& mystery_numbers, std::vector< int >& answer_numbers, int& cows, int& bulls )
{
    bulls = 0;
    cows = 0;
    for( int i = 0; i < 4; ++i )
    {
        if( mystery_numbers[i] == answer_numbers[i] )
        {
            ++bulls;
        }
    }

    for( int i = 0; i < 4; ++i )
    {
        for( int j = 0; j < 4; ++j )
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
void print_results( std::vector< int >& mystery_numbers, std::vector< int >& answer_numbers, int& cows, int& bulls )
{
//    std::cout << "Загадані числа: \n";
//    for( int x : mystery_numbers ) 
//    {
//        std::cout << x << '\t';
//    }
//    std::cout << '\n';
    std::cout << "Введені числа: \n";
    for( int y : answer_numbers ) 
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
    std::cout << "Вас вітає гра камінь 'Бички і корови'.\n";
    std::vector< int > mystery_numbers( 4 );
    std::vector< int > answer_numbers( 4 );
    int cows = 0;
    int bulls = 0;
    get_mystery_numbers( mystery_numbers );
    for(;;)
    {
        if( bulls == 4 )
        {
            std::cout << "Загадані числа: \n";
            for( int x : mystery_numbers ) 
            {
                std::cout << x << '\t';
            }
            std::cout << '\n';
            std::cout << "Вітаємо, ви відгадали всі числа на своїх місцях і перемогли! \n";
            break;
        }
        get_answer_numbers( answer_numbers );
        compare_numbers( mystery_numbers, answer_numbers, cows, bulls );
        print_results( mystery_numbers, answer_numbers, cows, bulls );
    }
	return 0;
}



