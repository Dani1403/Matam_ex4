#include "Well.h"

std::string Well::getName() const
{
	return "Well";
}

void Well::applyEncounter(Player& player) const
{
	if (player.getJob() == "Ninja")
	{
		printWellMessage(true);
	}
	else
	{
		player.damage(WELL_DAMAGE);
		printWellMessage(false);
	}
}
