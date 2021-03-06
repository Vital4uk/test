//програма видає список простих числел від одиниці до введеного числа
//згідно алгоритму, схожого на Решето Ератосфена 
#include <iostream>
#include <vector>

//функція введення числа
//повертає ціле число
//запобігає некоректному вводу числа
int get_number()
{
        while (true)
        {
                std::cout << "Введіть число, до якого будуть пораховані прості числа від одиниці: \n";
                int num = 0;
                std::cin >> num;
                if (std::cin.fail())    //якщо попереднє введене значення не вдале
                {
                        std::cin.clear(); //повертаємо cin в звичайний режи роботи
                        std::cin.ignore(32767, '\n'); //і видаляємо значення попереднього вводу
                        std::cout << "Введене не коректне значення, спробуйте знову. \n";                             //і вхідного буфера
                }
                else
                {
                        return num;
                }
        }
}

//функція приймає ціле число
//вираховує вектор простих чисел від 1 до заданого числа
//і повертає цей вектор
std::vector<int> get_primes (int num)
{
	std::vector<int> all_num;
	//заповнюємо вектор числами від одиниці до заданого числа
	for (int i = 1; i <= num; ++i)
	{
		all_num.push_back(i);
	}
	
	//цикл для заміни всіх не простих числел на нуль.
	//даним циклом перебираємо всі числа допоки добуток чисел не буде більше заданого
	//на можливість ділення на це число
	//не обов'язково перебирати всі числа до заданого, достатньо і цього
	//для правильного визначення всіх простих числел до заданого
	for (int j = 2; j * j < num; ++j) 
	{
        	//даним циклом перебираємо всі числа до заданого на можливість
		//ділення даного числа без залишку (складне число)
		for (int k = j + 1; k <= num; ++k) 
		{
            		//якщо залишок від ділення дорівнює 0 значить число не просте
			if (k % j == 0) 
			{
				//замінюємо його на нуль
				all_num[k-1] = 0;
            		}
        	}
    	}
	return all_num;	
}

int main ()
{
	int number = get_number();
	int l = 0;
	std::vector<int> rezult = get_primes(number);
	//виводимо везультуючий вектор з простими числами на друк
	for (int n : rezult)
	{
		//не виводимо нулі, якими ми замінили складні числа в векторі
		if (n != 0)
		{
			std::cout << n << "\t";
			//рахуємо кожен десятий вивід
			++l;
			//переходимо на нову строчку кожен десятий раз щоб сформувати 10 стовпчиків
			if (l % 10 == 0)
			{
				std::cout << "\n";
			}

		}
	}
	std::cout << "\n";
	return 0;
}
