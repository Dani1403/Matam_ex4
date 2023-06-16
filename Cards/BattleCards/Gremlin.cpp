#include "Gremlin.h"

Gremlin::Gremlin() : BattleCard(GREMLIN_LOOT, GREMLIN_DAMAGE, GREMLIN_FORCE){}

std::string Gremlin::getName() const
{
	return "Gremlin";
}