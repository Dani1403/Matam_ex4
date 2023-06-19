#include "Witch.h"

Witch::Witch() : BattleCard(WITCH_LOOT, WITCH_DAMAGE, WITCH_FORCE) {}

std::string Witch::getName() const
{
	return "Witch";
}