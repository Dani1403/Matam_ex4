#include "Merchant.h"

void applyChoice(Player& player, int choice) 
{
	switch (choice) {
		case(LEAVE) : 

	}
		
}

Merchant::Merchant() : Card() {}

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

void Merchant::printInfo() const
{
	return;
}