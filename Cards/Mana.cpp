#include "Mana.h"

Mana::Mana() : Card(0, 0, 0, HP_TO_HEAL) {}

std::string Mana::getName() const
{
	return "Mana";
}

void Mana::applyEncounter(Player& player) const
{
	if (player.getJob() == "Healer")
	{
		player.heal(HP_TO_HEAL);
		printManaMessage(true);
	}
	else
	{
		printManaMessage(false);
	}
}

void Mana::printInfo() const 
{
	return;
}
