//гра 'бики і корови' з літерами
#include <iostream>
#include <vector>
#include <stdlib.h>	//для виклику функції rand()
#include <time.h>	//для виклику функції time()
#include <ctime>    
#include <random>


//функція введення літери з необхідними обмеженнями
//повертає одну маленьку англійську літеру
//запобігає некоректному вводу
std::string get_letter( std::istream &stream = std::cin ) 
{
    while (true)
    {
        std::string letter;
        stream >> letter;
        try 
        {
            if( 1 != letter.size() ) //не пропускає білььше 1 введеного символа
            {
                throw std::invalid_argument( "Out of range 1 letter" );
            }
            if( "a" > letter || "z" < letter ) //не пропускає будь які символи крім маленьких англ. літер
            {
                throw std::invalid_argument( "Out of range a-z" );
            }
            stream.ignore(32767,'\n'); //забирає лишні введені символи
            return letter;
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

//функція генерації 4 випадкових літер
//видає вектор з 4 випадковими літерами
void get_mystery_letters( std::vector< std::string >& mystery_letters )
{
    std::string rand_letter;
    std::mt19937 gen ( time(NULL) );
    std::uniform_int_distribution <int> rn ( 'a', 'z' );

    for ( size_t index = 0u; index < mystery_letters.size(); )
    {
        rand_letter = rn( gen );
        std::string mystery_letter = rand_letter;
        bool is_unique = true;
        for( auto letter : mystery_letters ) 
        {
            if( letter == mystery_letter ) 
            {
                is_unique = false;
                break;
            }
        }
        if( is_unique ) 
        {
            mystery_letters[ index ] = mystery_letter;
            ++index;
        }
    }
}

//функція введення 4 літер щоб вгадати випадково загадані
//формує вектор з 4 введеними літерами
void get_answer_letters( std::vector< std::string >& answer_letters )
{
    answer_letters.assign( 4, "AA" );
    std::cout << '\n';
    for ( size_t index = 0u; index < answer_letters.size(); )
    {
        std::cout << "Введіть літеру #" << index + 1 << "\n";
        std::string answer_letter = get_letter( );
        bool is_unique = true;
        for( auto letter : answer_letters ) 
        {
            if( letter == answer_letter ) 
            {
                std::cout << "Введена літера #" << index + 1 << " співпадає з раніше введеною літерою." << "\n";
                std::cout << "Введіть літеру #" << index + 1 << " повторно:\n";
                is_unique = false;
                break;
            }
        }
        if( is_unique ) 
        {
            answer_letters[ index ] = answer_letter;
            ++index;
        }
    }
}

//функція порівняння вертора випадкових літер і введеного вектора
//і визначнення співпадіння літер і їх позицій відповідно до умов гри
void compare_letters( const std::vector< std::string >& mystery_letters, const std::vector< std::string >& answer_letters, int& cows, int& bulls )
{
    bulls = 0;
    cows = 0;
    for( size_t i = 0u; i < mystery_letters.size(); ++i )
    {
        if( mystery_letters[i] == answer_letters[i] )
        {
            ++bulls;
        }
    }

    for( size_t i = 0u; i < mystery_letters.size(); ++i )
    {
        for( size_t j = 0u; j < mystery_letters.size(); ++j )
        {
            if( mystery_letters[i] == answer_letters[j] )
            {
                ++cows;
            }
        }    
    }
    cows = cows - bulls;
}

//функція виводу результатів порівняння
void print_results( const std::vector< std::string >& mystery_letters, const std::vector< std::string >& answer_letters, int cows, int bulls )
{
    std::cout << "Загадані літери: \n";
    for( auto x : mystery_letters ) 
    {
       std::cout << x << '\t';
    }
    std::cout << '\n';
    std::cout << "Введені літери: \n";
    for( auto y : answer_letters ) 
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
    std::cout << "Намагаємося вгадати 4 літери.\n";
    std::cout << "Вводимо і вгадуємо лише маленькі англійські літери від 'a' до 'z'.\n";
    std::vector< std::string > mystery_letters( 4 );
    std::vector< std::string > answer_letters( 4 );
    std::cout << '\n';
    int cows = 0;
    int bulls = 0;
    get_mystery_letters( mystery_letters );
    for(;;)
    {
        if( bulls == 4 )
        {
            std::cout << "Загадані літери: \n";
            for( auto x : mystery_letters ) 
            {
                std::cout << x << '\t';
            }
            std::cout << '\n';
            std::cout << "Вітаємо, ви відгадали всі літери на своїх місцях і перемогли! \n";
            break;
        }
        get_answer_letters( answer_letters );
        compare_letters( mystery_letters, answer_letters, cows, bulls );
        print_results( mystery_letters, answer_letters, cows, bulls );
    }
	return 0;
}



