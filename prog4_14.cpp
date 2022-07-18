//Програма вгадує задумане число від 1 до 99 за 7 спроб 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{
	std::cout << "Задумайте ціле число від 1 до 99" << "\n";
	char answer = ' ';
	std::cout << "Число менше 50? введіть 'y' або 'n'" << "\n";
	std::cin >> answer;
	if (answer == 'y')
	{
		std::cout << "Число менше 25? введіть 'y' або 'n'" << "\n";
		std::cin >> answer;
		if (answer == 'y')
		{
			std::cout << "Число менше 12? введіть 'y' або 'n'" << "\n";
			std::cin >> answer;
			if (answer == 'y')
			{
				std::cout << "Число менше 6? введіть 'y' або 'n'" << "\n";
				std::cin >> answer;
				if (answer == 'y')
				{
					std::cout << "Число менше 3? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 2? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{	
							std::cout << "Загадане число = 1" << "\n";
						}
						else
						{	
							std::cout << "Загадане число = 2" << "\n";
						}
					}
					else if (answer == 'n')
					{	
						std::cout << "Число менше 5? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{	
							std::cout << "Число менше 4? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{	
								std::cout << "Загадане число = 3" << "\n";
							}
							else
							{	
								std::cout << "Загадане число = 4" << "\n";
							}
						}
						else
						{	
							std::cout << "Загадане число = 5" << "\n";
						}
					}
				}
				else if (answer == 'n')
				{
					std::cout << "Число менше 9? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 7? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{	
							std::cout << "Загадане число = 6" << "\n";
						}
					
						else if (answer == 'n')
						{	
							std::cout << "Число більше 7? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{	
								std::cout << "Загадане число = 8" << "\n";
							}
							else
							{	
								std::cout << "Загадане число = 7" << "\n";
							}
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 10? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Загадане число = 9" << "\n";
						}
						else if (answer == 'n')
						{
							std::cout << "Число більше 10? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 11" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 10" << "\n";
							}
						}
					}
				}
			}
			else if (answer == 'n')
			{
				std::cout << "Число менше 18? введіть 'y' або 'n'" << "\n";
				std::cin >> answer;
				if (answer == 'y')
				{
					std::cout << "Число менше 15? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 13? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
								std::cout << "Загадане число = 12" << "\n";
						}
						else if (answer == 'n')
						{
							std::cout << "Число більше 13? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 14" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 13" << "\n";
							}
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 16? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Загадане число = 15" << "\n";
						}
						else if (answer == 'n')
						{
							std::cout << "Число більше 16? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 17" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 16" << "\n";
							}
						}
					}
				}
				else if (answer == 'n')
				{
					std::cout << "Число менше 21? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 19? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Загадане число = 18" << "\n";
						}
						else if (answer == 'n')
						{
							std::cout << "Число більше 19? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 20" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 19" << "\n";
							}
						}							
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 23? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 22? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 21" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 22" << "\n";
							}
						}
						else if (answer == 'n')
						{
							std::cout << "Число менше 24? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 23" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 24" << "\n";
							}
						}
					}	
				}	
			}
		}
		else if (answer == 'n')
		{
			std::cout << "Число менше 37? введіть 'y' або 'n'" << "\n";
			std::cin >> answer;
			if (answer == 'y')
			{
				std::cout << "Число менше 31? введіть 'y' або 'n'" << "\n";
				std::cin >> answer;
				if (answer == 'y')
				{
					std::cout << "Число менше 28? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 27? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 26? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{	
								std::cout << "Загадане число = 25" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 26" << "\n";
							}
						}
						else
						{
							std::cout << "Загадане число = 27" << "\n";
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 30? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 29? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 28" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 29" << "\n";
							}
						}
						else 
						{
							std::cout << "Загадане число = 30" << "\n";
						}
					}
				}
				else if (answer == 'n')
				{
					std::cout << "Число менше 34? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 32? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Загадане число = 31" << "\n";
						}
						else if (answer == 'n')
						{
							std::cout << "Число менше 33? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 32" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 33" << "\n";
							}
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 36? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 35? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 34" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 35" << "\n";
							}
						}
						else
						{
							std::cout << "Загадане число = 36" << "\n";
						}
					}

				}
			}
			else if (answer == 'n')
			{
				std::cout << "Число менше 43? введіть 'y' або 'n'" << "\n";
				std::cin >> answer;
				if (answer == 'y')
				{
					std::cout << "Число менше 40? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 39? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 38? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 37" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 38" << "\n";
							} 
						}
						else
						{
							std::cout << "Загадане число = 39" << "\n";
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 42? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 41? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 40" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 41" << "\n";
							}
						}
						else
						{
							std::cout << "Загадане число = 42" << "\n";
						}
					}
				}
				else if (answer == 'n')
				{
					std::cout << "Число менше 46? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 45? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 44? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 43" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 44" << "\n";
							}
						}
						else
						{
							std::cout << "Загадане число = 45" << "\n";
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 48? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 47? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 46" << "\n";
							}	
							else
							{
								std::cout << "Загадане число = 47" << "\n";
							}
						}
						else if (answer == 'n')
						{
							std::cout << "Число менше 49? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 48" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 49" << "\n";
							}
						}
					}	
				}
			}
		}
	}
	else if (answer == 'n')
	{
		std::cout << "Число менше 75? введіть 'y' або 'n'" << "\n";
		std::cin >> answer;
		if (answer == 'y')
		{
			std::cout << "Число менше 62? введіть 'y' або 'n'" << "\n";
			std::cin >> answer;
			if (answer == 'y')
			{
				std::cout << "Число менше 56? введіть 'y' або 'n'" << "\n";
				std::cin >> answer;
				if (answer == 'y')
				{
					std::cout << "Число менше 53? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 52? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{	
							std::cout << "Число менше 51? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 50" << "\n";
							}
							else
							{	
								std::cout << "Загадане число = 51" << "\n";
							}
						}
						else
						{
							std::cout << "Загадане число = 52" << "\n";
						}

					}
					else if (answer == 'n')
					{	
						std::cout << "Число менше 55? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{	
							std::cout << "Число менше 54? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{	
								std::cout << "Загадане число = 53" << "\n";
							}
							else
							{	
								std::cout << "Загадане число = 54" << "\n";
							}
						}
						else
						{	
							std::cout << "Загадане число = 55" << "\n";
						}
					}
				}
				else if (answer == 'n')
				{
					std::cout << "Число менше 59? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 57? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{	
							std::cout << "Загадане число = 56" << "\n";
						}
					
						else if (answer == 'n')
						{	
							std::cout << "Число більше 57? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{	
								std::cout << "Загадане число = 58" << "\n";
							}
							else
							{	
								std::cout << "Загадане число = 57" << "\n";
							}
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 60? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Загадане число = 59" << "\n";
						}
						else if (answer == 'n')
						{
							std::cout << "Число більше 60? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 61" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 60" << "\n";
							}
						}
					}
				}
			}
			else if (answer == 'n')
			{
				std::cout << "Число менше 68? введіть 'y' або 'n'" << "\n";
				std::cin >> answer;
				if (answer == 'y')
				{
					std::cout << "Число менше 65? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 63? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
								std::cout << "Загадане число = 62" << "\n";
						}
						else if (answer == 'n')
						{
							std::cout << "Число більше 63? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 64" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 63" << "\n";
							}
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 66? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Загадане число = 65" << "\n";
						}
						else if (answer == 'n')
						{
							std::cout << "Число більше 66? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 67" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 66" << "\n";
							}
						}
					}
				}
				else if (answer == 'n')
				{
					std::cout << "Число менше 71? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 69? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Загадане число = 68" << "\n";
						}
						else if (answer == 'n')
						{
							std::cout << "Число більше 69? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 70" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 69" << "\n";
							}
						}							
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 73? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 72? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 71" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 72" << "\n";
							}
						}
						else if (answer == 'n')
						{
							std::cout << "Число менше 74? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 73" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 74" << "\n";
							}
						}
					}	
				}	
			}
		}
		else if (answer == 'n')
		{
			std::cout << "Число менше 87? введіть 'y' або 'n'" << "\n";
			std::cin >> answer;
			if (answer == 'y')
			{
				std::cout << "Число менше 81? введіть 'y' або 'n'" << "\n";
				std::cin >> answer;
				if (answer == 'y')
				{
					std::cout << "Число менше 78? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 77? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 76? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{	
								std::cout << "Загадане число = 75" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 76" << "\n";
							}
						}
						else
						{
							std::cout << "Загадане число = 77" << "\n";
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 80? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 79? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 78" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 79" << "\n";
							}
						}
						else 
						{
							std::cout << "Загадане число = 80" << "\n";
						}
					}
				}
				else if (answer == 'n')
				{
					std::cout << "Число менше 84? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 82? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Загадане число = 81" << "\n";
						}
						else if (answer == 'n')
						{
							std::cout << "Число менше 83? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 82" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 83" << "\n";
							}
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 86? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 85? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 84" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 85" << "\n";
							}
						}
						else
						{
							std::cout << "Загадане число = 86" << "\n";
						}
					}

				}
			}
			else if (answer == 'n')
			{
				std::cout << "Число менше 93? введіть 'y' або 'n'" << "\n";
				std::cin >> answer;
				if (answer == 'y')
				{
					std::cout << "Число менше 90? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 89? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 88? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 87" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 88" << "\n";
							} 
						}
						else
						{
							std::cout << "Загадане число = 89" << "\n";
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 92? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 91? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 90" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 91" << "\n";
							}
						}
						else
						{
							std::cout << "Загадане число = 92" << "\n";
						}
					}
				}
				else if (answer == 'n')
				{
					std::cout << "Число менше 96? введіть 'y' або 'n'" << "\n";
					std::cin >> answer;
					if (answer == 'y')
					{
						std::cout << "Число менше 95? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 94? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 93" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 94" << "\n";
							}
						}
						else
						{
							std::cout << "Загадане число = 95" << "\n";
						}
					}
					else if (answer == 'n')
					{
						std::cout << "Число менше 98? введіть 'y' або 'n'" << "\n";
						std::cin >> answer;
						if (answer == 'y')
						{
							std::cout << "Число менше 97? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 96" << "\n";
							}	
							else
							{
								std::cout << "Загадане число = 97" << "\n";
							}
						}
						else if (answer == 'n')
						{
							std::cout << "Число менше 99? введіть 'y' або 'n'" << "\n";
							std::cin >> answer;
							if (answer == 'y')
							{
								std::cout << "Загадане число = 98" << "\n";
							}
							else
							{
								std::cout << "Загадане число = 99" << "\n";
							}
						}
					}	
				}
			}
		}
	}
	
return 0;
}


