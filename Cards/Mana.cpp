#include "Mana.h"

std::string Mana::getName() const
{
	return "Mana";
}

void Mana::applyEncounter(Player& player) const
{
	if (player.getJob() == "Healer")
	{
		player.heal(MANA_HEAL);
		printManaMessage(true);
	}
	else
	{
		printManaMessage(false);
	}
}

