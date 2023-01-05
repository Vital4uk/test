//програма приймає значення кількості чисел що необхідно просумувати
//і значення які необхідно просумувати
//вивдодить введені значення і суму
#include <iostream>
#include <vector>
#include <sstream> //підключає std::stringstream

//функція вводу слів
//приймає слова, які відповідають заданим попередньо у векторі
//повертає вектор з введеними словами
void read_data( std::vector< std::string >& input_words, std::vector< std::string > words, std::istream &stream = std::cin) {
    std::string word;
    std::cout << "Input sentence with words 'birds', 'fish', 'C++', " 
        << "'rules', 'fly', 'swim', 'and', 'or', 'but', 'the'. \n" << "It must end with 'space' + '.' \n";
    
    for(;;) 
    {
        stream >> word;
        if ("." == word) 
        {
            return;
        }
        bool check = false;
        for( auto x : words)
        {
            if( x == word )
            {
                check = true;
            }
        }
        if( check == true )
        {
            input_words.push_back( word );
        }
        else
        {
            std::cout << "Incorrect word" << '\n';
        }
    }
}

//порівнює введені слова з заданими словами на розташування у правильному порядку
//повертає статус чи формуютсья введені слова у правильне речення
void comparison( std::vector< std::string > input_words, std::vector< std::string > noun, 
        std::vector< std::string > verb, std::vector< std::string > conjunctive, 
        std::string article, bool& correctness )
{
    bool check1 = false;
    bool check2 = false;
    bool check3 = false;
    bool check4 = false;
    bool check5 = false;
    bool check6 = false;
    bool check7 = false;

//for 0 words ---------------------------------    
    
    if( input_words.size() == 0 )
    {
        correctness = false; 
    }

//for 1 words ---------------------------------    
    
    if( input_words.size() == 1 )
    {
        correctness = false; 
    }

//for 2 words ---------------------------------    
    
    if( input_words.size() == 2 )
    {
        for( auto n : noun )
        {
            if( n == input_words[0] )
            {
                check1 = true;
            }
        }
        for( auto v : verb )
        {
            if( v == input_words[1] )
            {
                check2 = true;
            }
        }
        if( check1 == true && check2 == true )
        {
            correctness = true; 
        }
        else
        {
            correctness = false; 
        } 
    }

//for 3 words ---------------------------------    
    
    if( input_words.size() == 3 )
    {
        if( input_words[0] == article )
        {
            check1 = true;
        }
        for( auto n : noun )
        {
            if( n == input_words[1] )
            {
                check2 = true;
            }
        }
        for( auto v : verb )
        {
            if( v == input_words[2] )
            {
                check3 = true;
            }
        }
        if( true == check1 && true == check2 && true == check3  )
        {
            correctness = true; 
        }
        else
        {
            correctness = false; 
        } 
    }

//for 4 words ---------------------------------    
    
    if( input_words.size() == 4 )
    {
        correctness = false; 
    }

//for 5 words ---------------------------------    
    
    if( input_words.size() == 5 )
    {
        for( auto n : noun )
        {
            if( n == input_words[0] )
            {
                check1 = true;
            }
        }
        for( auto v : verb )
        {
            if( v == input_words[1] )
            {
                check2 = true;
            }
        }
        for( auto c : conjunctive )
        {
            if( c == input_words[2] )
            {
                check3 = true;
            }
        }
        for( auto n2 : noun )
        {
            if( n2 == input_words[3] )
            {
                check4 = true;
            }
        }
        for( auto v2 : verb )
        {
            if( v2 == input_words[4] )
            {
                check5 = true;
            }
        }
        if( true == check1 && true == check2 && true == check3 && true == check4 && true == check5 )
        {
            correctness = true; 
        }
        else
        {
            correctness = false; 
        } 
    }

//for 6 words ---------------------------------    
    
    if( input_words.size() == 6 )
    {
        if( input_words[0] == article )
        {
            check1 = true;
            for( auto n : noun )
            {
                if( n == input_words[1] )
                {
                    check2 = true;
                }
            }
            for( auto v : verb )
            {
                if( v == input_words[2] )
                {
                    check3 = true;
                }
            }
            for( auto c : conjunctive )
            {
                if( c == input_words[3] )
                {
                    check4 = true;
                }
            }
            for( auto n2 : noun )
            {
                if( n2 == input_words[4] )
                {
                    check5 = true;
                }
            }
            for( auto v2 : verb )
            {
                if( v2 == input_words[5] )
                {
                    check6 = true;
                }
            }
            if( true == check1 && true == check2 && true == check3 && true == check4 
                    && true == check5 && true == check6 )
            {
                correctness = true; 
            }
            else
            {
                correctness = false; 
            }
        }
        else if( input_words[3] == article )
        {
            check4 = true;
            for( auto n : noun )
            {
                if( n == input_words[0] )
                {
                    check1 = true;
                }
            }
            for( auto v : verb )
            {
                if( v == input_words[1] )
                {
                    check2 = true;
                }
            }
            for( auto c : conjunctive )
            {
                if( c == input_words[2] )
                {
                    check3 = true;
                }
            }
            for( auto n2 : noun )
            {
                if( n2 == input_words[4] )
                {
                    check5 = true;
                }
            }
            for( auto v2 : verb )
            {
                if( v2 == input_words[5] )
                {
                    check6 = true;
                }
            }
            if( true == check1 && true == check2 && true == check3 && true == check4 && true == check5 && true == check6 )
            {
                correctness = true; 
            }
            else
            {
                correctness = false; 
            }
        }
        else
        {
            correctness = false; 
        }        
    }

//for 7 words ---------------------------------    
    
    if( input_words.size() == 7 )
    {
        if( input_words[0] == article )
        {
            check1 = true;
        }
        for( auto n : noun )
        {
            if( n == input_words[1] )
            {
                check2 = true;
            }
        }
        for( auto v : verb )
        {
            if( v == input_words[2] )
            {
                check3 = true;
            }
        }
        for( auto c : conjunctive )
        {
            if( c == input_words[3] )
            {
                check4 = true;
            }
        }
        if( input_words[4] == article )
        {
            check5 = true;
        }
        for( auto n2 : noun )
        {
            if( n2 == input_words[5] )
            {
                check6 = true;
            }
        }
        for( auto v2 : verb )
        {
            if( v2 == input_words[6] )
            {
                check7 = true;
            }
        }
        if( true == check1 && true == check2 && true == check3 && true == check4 
                && true == check5 && true == check6 && true == check7)
        {
            correctness = true; 
        }
        else
        {
            correctness = false; 
        } 
    }

//for more than 7 words ---------------------------------    
    
    if( input_words.size() > 7 )
    {
        correctness = false;
    } 
}

//Функція друку результатів роботи програми
void print_results( std::vector< std::string > input_words, bool correctness ) 
{
    std::cout << "Input words: " << '\n'; 
    for( auto x : input_words) 
    {
        std::cout << x << " ";
    }
    std::cout << '\n';
    if( correctness == true )
    {    
        std::cout << "Sentence CORRECT" << '\n'; 
    }
    else
    {
        std::cout << "Sentence INCORRECT" << '\n'; 
    }
}

int main()
{
    const std::vector< std::string > noun = { "birds", "fish", "C++" };
    const std::vector< std::string > verb = { "rules", "fly", "swim" };
    const std::vector< std::string > conjunctive = { "and", "or", "but" };
    const std::string article = "the";
    const std::vector< std::string > words = { "birds", "fish", "C++", 
        "rules", "fly", "swim", "and", "or", "but" , "the" };
    std::vector< std::string > input_words;
    bool correctness = false;
    
    read_data( input_words, words );
    comparison( input_words, noun, verb, conjunctive, article,  correctness );
    print_results( input_words, correctness );

	return 0;	
}
