//програма виводить список введених слів 
//з заміненими не бажаними словами
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<std::string> words; //об'являємо вектор words
	for (std::string temp; std::cin >> temp; ) //поки вводяться слова
	{					//записуємо слово в змінну temp
		words.push_back (temp);		//записуємо слово з temp
	}					//в кінець вектора words (новий елемент вектора
	std::cout << "Rezult: \n";

	std::vector<std::string> disliked = {"broccoli", "tomato", "potato", "strawberry" }; //масив слів які треба замінювати

	bool print;
	for (int i = 0; i < words.size(); ++i) //проганяємо весь масив введених слів
	{
		for (int j = 0; j < disliked.size(); ++j) //проганяємо весь масив заборонених слів
		{
			if (words[i] == disliked[j]) //якщо введене слово співпадає із словом з масиву
			{
				std::cout << "BLEEP" << "\n";//запікуємо
				print = true;	//позначка що слово вже запікане
				j = disliked.size(); //зупинка перевірки введеного слова з наступники в бібілотеці запікуваних слів 
 // потрібно для того, щоб перевірка цього ж слова з наступним в бібліотеці
 // запікуваних не привела нас в else що в свою чергу приведе нас
 // до не правильного друку цього ж слова після того як запікаємо його
			}
			else
			{
				print = false;
			}
		}	
		if (print == false)
		{
			std::cout << words[i] << "\n";
			//якщо дане слово не запікали, друкуємо його
		}
	}

	return 0;	
}
