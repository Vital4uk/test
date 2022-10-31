
#include "Token.h"

namespace calculator
{

// The putback() member function puts its argument back into the Token_stream's
// buffer:
void
Token_stream::Token_stream::putback( Token t )
{
    if ( full )
    {
        throw std::runtime_error( "putback() into a full buffer" );
    }
    buffer = t;  // copy t to buffer
    full = true; // buffer is now full
}

//------------------------------------------------------------------------------

Token
Token_stream::Token_stream::get( )
{
    if ( full )
    { // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

    switch ( ch )
    {
    case '=': // for "print"
    case 'x': // for "quit"
    case '{':
    case '}':
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '!':
    {
        return Token( ch ); // let each character represent itself
    }
    case '.':
        //   case '-1':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    {
        std::cin.putback( ch ); // put digit back into the input stream
        double val;
        std::cin >> val;          // read a floating-point number
        return Token( '7', val ); // let '8' represent "a number"
    }
    default:
    {
        throw std::runtime_error( "Bad token" );
    }
    }
}
} // namespace calculator