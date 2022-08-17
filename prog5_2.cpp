//програма переводу градусів цельсія у кельвіни
#include <iostream>

double ctok( double c )
{
    double k = c + 273.15;    
    return k;
}

int main ()
{
    double c = 0;
    std::cin >> c;
    if( c < -273.15 )
    {
        std::cout << "Введена значення температури нижче абсолютного нуля" << std::endl;
    }
    else 
    {
        double k = ctok( c );
        std::cout << k << "\n";
    }
    return 0;    
}
