#include "Treasure.h"

void Treasure::applyEncounter(Player& player) const
{
	player.addCoins(TREASURE_COINS);
	printTreasureMessage();
}

std::string Treasure::getName() const
{
	return "Treasure";
}