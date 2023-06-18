#include "Witch.h"
#include "../../Players/Ninja.h"

Witch::Witch() : BattleCard(WITCH_LOOT, WITCH_DAMAGE, WITCH_FORCE) {}

std::string Witch::getName() const
{
	return "Witch";
}