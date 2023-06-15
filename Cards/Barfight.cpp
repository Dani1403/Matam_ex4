#include "Barfight.h"

std::string Barfight::getName() const
{
	return "Barfight";
}

void Barfight::applyEncounter(Player& player) const
{
	if (player.getJob() == "Warrior")
	{
		printBarfightMessage(true);
	}
	else
	{
		player.damage(this->getDamage());
		printBarfightMessage(false);
	}
}

int Barfight::getDamage() const
{
	return this->BARFIGHT_DAMAGE;
}

