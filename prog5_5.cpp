//програма переводу градусів цельсія у кельвіни
#include <iostream>
#include <cassert>

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

double ctok( double c )
{
    //якщо ведене число виконує умову перевірки,
    //assertm дозволяє продовжувати виконувати наступні інструкції
    assertm( -273.15 <= c, "Введене значення температури нижче абсолютного нуля");
    double k = c + 273.15;    
    return k;
}

int main ()
{
    double c = 0;
    std::cin >> c;
    double k = ctok( c );
    std::cout << k << "\n";
    return 0;    
}
