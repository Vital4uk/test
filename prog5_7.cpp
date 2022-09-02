//програма переводу градусів цельсія у фаренгейти
#include <iostream>
#include <cassert>

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

double ctof( double c )
{
    //якщо ведене число виконує умову перевірки,
    //assertm дозволяє продовжувати виконувати наступні інструкції
    assertm( -273.15 <= c, "Введене значення температури нижче абсолютного нуля");
    double f = 9.0 / 5 * c + 32;
    return f;
}

int main ()
{
    double c = 0;
    std::cin >> c;
    double f = ctof( c );
    std::cout << f << "\n";
    return 0;    
}
