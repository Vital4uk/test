// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file is known as calculator02buggy.cpp

    I have inserted 5 errors that should cause this not to compile
    I have inserted 3 logic errors that should cause the program to give wrong results

    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)

    Happy hunting!

*/

//#include "../std_lib_facilities.h"
#include <iostream>


//------------------------------------------------------------------------------

class Token
{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream 
{
public:
//    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full {false};        // is there a Token in the buffer?
    Token buffer = 0;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
//Token_stream::Token_stream()
//{
//    full = false; 
//    buffer = 0;    // no Token in buffer
//}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) 
    {
        throw std::runtime_error("putback() into a full buffer");
    }
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) 
    {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) 
    {
        case '=':    // for "print"
        case 'x':    // for "quit"
        case '{': case '}': case '(': case ')': case '+': case '-': case '*': case '/': case '!':
        {
            return Token(ch);        // let each character represent itself
        }
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            std::cin.putback(ch);         // put digit back into the input stream
            double val;
            std::cin >> val;              // read a floating-point number
            return Token('8', val);   // let '8' represent "a number"
        }
        default:
        {
            throw std::runtime_error("Bad token");
        }
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) 
    {
        case '{':    // handle '{' expression '}'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}')
            {  
                throw std::runtime_error("'}' expected");
            }
            return d; 
        }
        case '(':    // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
            {  
                throw std::runtime_error("')' expected");
            }
            return d; 
        }
        case '8':            // we use '8' to represent a number
        {
            return t.value;  // return the number's value
        }
        default:
        {
            throw std::runtime_error("primary expected");
        }
    }
}

//------------------------------------------------------------------------------

// deal with ! 
double factorial()
{
    double left = primary();    //need it double for other cases
    Token t = ts.get();        // get the next token from token stream

    while (true) 
    {
        switch (t.kind) 
        {
            case '!':
            {
                double temp = left;
                int f = left;
                if( (temp - f) != 0 ) 
                {
                    throw std::runtime_error("int number expect for '!'");
                }
                if (f == 0) 
                {
                    left = 1;
                    t = ts.get();
                    break;                    
                }
                left = 1;
                for( int i = 1; i <= f; ++i )
                {
                    left *= i;
                }
                t = ts.get();
                break;
            }
            default:
            {
                ts.putback(t);     // put t back into the token stream
                return left;
            }
        }
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = factorial();
    Token t = ts.get();        // get the next token from token stream

    while (true) 
    {
        switch (t.kind) 
        {
            case '*':
            {
                left *= factorial();
                t = ts.get();
                break;
            }
            case '/':
            {
                double d = factorial();
                if (d == 0) 
                {
                    throw std::runtime_error("divide by zero");
                }
                left /= d;
                t = ts.get();
                break;
            }
            default:
            {
                ts.putback(t);     // put t back into the token stream
                return left;
            }
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) 
    {
        switch (t.kind) 
        {
            case '+':
            {
                left += term();    // evaluate Term and add
                t = ts.get();
                break;
            }
            case '-':
            {   
                left -= term();    // evaluate Term and subtract
                t = ts.get();
                break;
            }
            default:
            {   ts.putback(t);     // put t back into the token stream
                return left;       // finally: no more + or -: return the answer
            }
        }
    }
}

//------------------------------------------------------------------------------

int main()
{
    std::cout << "Welcome to Calculator!" << '\n';
    std::cout << "Input math exspression." << '\n';
    std::cout << "Use symbols '{' '}' '(' ')' for math expressions" << '\n';
    std::cout << "Use numbers '0-9' and math symbols '+' '-' '*' '/' '!'." << '\n';
    std::cout << "Use '=' to end the exspression and print results." << '\n';
    std::cout << "Use 'x' to Quit the program." << '\n';
    try
    {
        double val = 0.0;
        while (std::cin) 
        {
            Token t = ts.get();
            if (t.kind == 'x') 
            {
                break; // 'x' for quit
            }
            if (t.kind == '=')        // '=' for "print now"
            {    
                std::cout << "=" << val << '\n';
            }
            else
            {   
                ts.putback(t);
                val = expression();
            }
        }
    return 0;
//    keep_window_open();
    }
    catch (std::exception& e) 
    {
        std::cerr << "error: " << e.what() << '\n';
//    keep_window_open();
        return 1;
    }
    catch (...) 
    {
        std::cerr << "Oops: unknown exception!\n";
//    keep_window_open();
        return 2;
    }
}
//-----------------------------------------------------------------------------
