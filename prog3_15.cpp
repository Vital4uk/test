//програма зчитує кількість монет кожного виду і видає їх загальну вартість
#include <iostream>
#include <string>
#include <vector>

int main()
{
	int coin_10_kop, coin_50_kop, coin_1_grn, coin_2_grn, coin_5_grn, coin_10_grn, kop_sum, grn_sum;
	const std::string prompt_string {"Введіть кількість монет номіналом "};

	std::cout << prompt_string << "10 коп: \n";
	std::cin >> coin_10_kop;
	std::cout << prompt_string << "50 коп: \n";
	std::cin >> coin_50_kop;
	std::cout << prompt_string << "1 грн: \n";
	std::cin >> coin_1_grn;
	std::cout << prompt_string << "2 грн: \n";
	std::cin >> coin_2_grn;
	std::cout << prompt_string << "5 грн: \n";
	std::cin >> coin_5_grn;
	std::cout << prompt_string << "10 грн: \n";
	std::cin >> coin_10_grn;
	
	//якщо залишок від ділення кількості монет 10 коп дорівнює одиниці і кількість монет 10 коп
	//не дорівнює 11 то "монета", тобто залишок від ділення на 10 потрібен для того,
	//щоб використати останню цифру числа кількості монет і відносно неї 
	//граматично правильно написати слово "монета" чи "монети" чи "монет"
	if (coin_10_kop % 10 == 1 && coin_10_kop != 11)
	{
		std::cout << "У вас " << coin_10_kop << " монета номіналом 10 коп." << "\n";
	}
	else 	if (coin_10_kop % 10 == 2 && coin_10_kop != 12 || coin_10_kop % 10 == 3 && coin_10_kop != 13 || coin_10_kop % 10 == 4 && coin_10_kop != 14) //схожий з попереднім if вираз з додаванням || (або), тобто якщо залишок = 2 або 3 або 4, то...
	{	
		std::cout << "У вас " << coin_10_kop << " монети номіналом 10 коп." << "\n";
	}
	else 
	{	
		std::cout << "У вас " << coin_10_kop << " монет номіналом 10 коп." << "\n";
	}
	
	if (coin_50_kop % 10 == 1 && coin_50_kop != 11)
	{
		std::cout << "У вас " << coin_50_kop << " монета номіналом 50 коп." << "\n";
	}
	else 	if (coin_50_kop % 10 == 2 && coin_50_kop != 12 || coin_50_kop % 10 == 3 && coin_50_kop != 13 || coin_50_kop % 10 == 4 && coin_50_kop != 14)
	{	
		std::cout << "У вас " << coin_50_kop << " монети номіналом 50 коп." << "\n";
	}
	else 
	{	
		std::cout << "У вас " << coin_50_kop << " монет номіналом 50 коп." << "\n";
	}
	
	if (coin_1_grn % 10 == 1 && coin_1_grn != 11)
	{
		std::cout << "У вас " << coin_1_grn << " монета номіналом 1 грн" << "\n";
	}
	else 	if (coin_1_grn % 10 == 2 && coin_1_grn != 12 || coin_1_grn % 10 == 3 && coin_1_grn != 13 || coin_1_grn % 10 == 4 && coin_1_grn != 14)
	{	
		std::cout << "У вас " << coin_1_grn << " монети номіналом 1 грн" << "\n";
	}
	else 
	{	
		std::cout << "У вас " << coin_1_grn << " монет номіналом 1 грн" << "\n";
	}
	
	if (coin_2_grn % 10 == 1 && coin_2_grn != 11)
	{
		std::cout << "У вас " << coin_2_grn << " монета номіналом 2 грн" << "\n";
	}
	else 	if (coin_2_grn % 10 == 2 && coin_2_grn != 12 || coin_2_grn % 10 == 3 && coin_2_grn != 13 || coin_2_grn % 10 == 4 && coin_2_grn != 14)
	{	
		std::cout << "У вас " << coin_2_grn << " монети номіналом 2 грн" << "\n";
	}
	else 
	{	
		std::cout << "У вас " << coin_2_grn << " монет номіналом 2 грн" << "\n";
	}
	
	if (coin_5_grn % 10 == 1 && coin_5_grn != 11)
	{
		std::cout << "У вас " << coin_5_grn << " монета номіналом 5 грн" << "\n";
	}
	else 	if (coin_5_grn % 10 == 2 && coin_5_grn != 12 || coin_5_grn % 10 == 3 && coin_5_grn != 13 || coin_5_grn % 10 == 4 && coin_5_grn != 14)
	{	
		std::cout << "У вас " << coin_5_grn << " монети номіналом 5 грн" << "\n";
	}
	else 
	{	
		std::cout << "У вас " << coin_5_grn << " монет номіналом 5 грн" << "\n";
	}
	
	if (coin_10_grn % 10 == 1 && coin_10_grn != 11)
	{
		std::cout << "У вас " << coin_10_grn << " монета номіналом 10 грн" << "\n";
	}
	else 	if (coin_10_grn % 10 == 2 && coin_10_grn != 12 || coin_10_grn % 10 == 3 && coin_10_grn != 13 || coin_10_grn % 10 == 4 && coin_10_grn != 14)
	{	
		std::cout << "У вас " << coin_10_grn << " монети номіналом 10 грн" << "\n";
	}
	else 
	{	
		std::cout << "У вас " << coin_10_grn << " монет номіналом 10 грн" << "\n";
	}

	kop_sum = coin_10_kop*10 + coin_50_kop*50; //сума копійок
	grn_sum = coin_1_grn + coin_2_grn*2 + coin_5_grn*5 + coin_10_grn*10 + kop_sum/100; //сума всіх гривень з гривнями з копійок

	if (grn_sum % 10 == 1 && grn_sum != 11)
	{
		std::cout << "Всього у вас " << grn_sum << " гривня" << " і " << kop_sum % 100 << " копійок" << "\n";
	}
	else 	if (grn_sum % 10 == 2 && grn_sum != 12 || grn_sum % 10 == 3 && grn_sum != 13 || grn_sum % 10 == 4 && grn_sum != 14)
	{	
	std::cout << "Всього у вас " << grn_sum << " гривні" << " і " << kop_sum % 100 << " копійок" << "\n";
	}
	else 
	{	
	std::cout << "Всього у вас " << grn_sum << " гривень" << " і " << kop_sum % 100 << " копійок" << "\n";
	}

	return 0;

}
