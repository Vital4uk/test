#include <iostream>
#include <stdexcept>

namespace calculator
{

class Token
{
public:
    Token( char ch ) // make a Token from a char
        : kind( ch )
        , value( 0 )
    {
    }
    Token( char ch, double val ) // make a Token from a char and a double
        : kind( ch )
        , value( val )
    {
    }

public:
    char kind;    // what kind of token
    double value; // for numbers: a value
};

class Token_stream
{
public:
    Token_stream( ) = default; // make a Token_stream that reads from cin
    Token get( );              // get a Token (get() is defined elsewhere)
    void putback( Token t );   // put a Token back

private:
    Token buffer{ '0' }; // here is where we keep a Token put back using putback()
    bool full{ false };  // is there a Token in the buffer?
};

} // namespace calculator