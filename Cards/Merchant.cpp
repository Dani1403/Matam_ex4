#include "Merchant.h"

//TODO : Complete applyChoice and encounter

void applyChoice(Player& player, int choice) 
{
	return;
}

void Merchant::applyEncounter(Player& player) const
{
	printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
	int choice;
	std::cin >> choice;
	applyChoice(player, choice);
}

std::string Merchant::getName() const
{
	return "Merchant";
}
