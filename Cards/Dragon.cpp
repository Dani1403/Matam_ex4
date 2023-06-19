#include "Dragon.h"

Dragon::Dragon() : BattleCard(DRAGON_LOOT, DRAGON_DAMAGE, DRAGON_FORCE) {}

std::string Dragon::getName() const
{
	return "Dragon";
}