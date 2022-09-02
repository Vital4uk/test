//програма переводу кельвінів у градуси цельсія
#include <iostream>
#include <cassert>

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

double ktoc( double k )
{
    //якщо ведене число виконує умову перевірки,
    //assertm дозволяє продовжувати виконувати наступні інструкції
    assertm( 0 <= k, "Введене значення температури нижче абсолютного нуля");
    double c = k - 273.15;    
    return c;
}

int main ()
{
    double k = 0;
    std::cin >> k;
    double c = ktoc( k );
    std::cout << c << "\n";
    return 0;    
}
