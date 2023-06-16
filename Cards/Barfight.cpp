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
		player.damage(BARFIGHT_DAMAGE);
		printBarfightMessage(false);
	}
}
