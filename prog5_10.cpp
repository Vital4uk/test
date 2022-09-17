//програма приймає значення кількості чисел що необхідно просумувати
//і значення які необхідно просумувати
//вивдодить введені значення і суму
#include <iostream>
#include <limits> // підключає std::numeric_limits

int main()
{
    long number1 = 0;
    long number2 = 1;
    long sum = 0;
    int max = 0;

    while( sum <= std::numeric_limits< int >::max() ) {
        sum = number1 + number2;
//        std::cout << sum << '\n';
        number1 = number2;
        number2 = sum;
        max = number1;
    }
    std::cout << "Найбільше число Фібоначчі, яке можна записати в змінну типу int: \n" << max << '\n';
    return 0;
}

