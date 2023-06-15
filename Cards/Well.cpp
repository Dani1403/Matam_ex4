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
		player.damage(this->getDamage());
		printWellMessage(false);
	}
}

int Well::getDamage() const
{
	return this->WELL_DAMAGE;
}