#include "Merchant.h"

/*
* Helper functions
*/
void applyChoice(Player& player, int choice);
int getChoice();

int getChoice()
{
	bool inputValid = true;
	int input = 0;
	std::string initial = " ";
	do
	{
		inputValid = true;
		try
		{
			std::getline(std::cin, initial);
			input = stoi(initial);
		}
		catch (std::exception&)
		{
			inputValid = false;
		}
		if (!inputValid || (input != LEAVE && input != HEALTH && input != FORCE))
		{
			printInvalidInput();
		}
	} while (!inputValid || (input != LEAVE && input != HEALTH && input != FORCE));
	return input;
}

void applyChoice(Player& player, int choice) 
{
	switch (choice)
	{
		case LEAVE:
			printMerchantSummary(std::cout, player.getName(), LEAVE, 0);
			break;
		case HEALTH:
			if (!player.pay(HEALTH_POTION_COST))
			{
				printMerchantInsufficientCoins(std::cout);
			}
			else
			{
				player.heal(HEALTH_POTION);
				printMerchantSummary(std::cout, player.getName(), HEALTH, HEALTH_POTION_COST);
			}
			break;
		case FORCE:
			if (!player.pay(FORCE_BOOST_COST))
			{
				printMerchantInsufficientCoins(std::cout);
			}
			else
			{
				player.buff(FORCE_BOOST);
				printMerchantSummary(std::cout, player.getName(), FORCE, FORCE_BOOST_COST);
			}
			break;
		default:
			break;
	}
}

void Merchant::applyEncounter(Player& player) const
{
	printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
	int choice = getChoice();
	applyChoice(player, choice);
}

std::string Merchant::getName() const
{
	return "Merchant";
}
