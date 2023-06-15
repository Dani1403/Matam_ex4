#include "Mana.h"

std::string Mana::getName() const
{
	return "Mana";
}

void Mana::applyEncounter(Player& player) const
{
	if (player.getJob() == "Healer")
	{
		player.heal(this->getHeal());
		printManaMessage(true);
	}
	else
	{
		printManaMessage(false);
	}
}

int Mana::getHeal() const
{
	return this->MANA_HEAL;
}


