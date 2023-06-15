#include "Treasure.h"

void Treasure::applyEncounter(Player& player) const
{
	player.addCoins(this->getCoins());
	printTreasureMessage();
}

std::string Treasure::getName() const
{
	return "Treasure";
}

int Treasure::getCoins() const
{
	return TREASURE_COINS;
}
