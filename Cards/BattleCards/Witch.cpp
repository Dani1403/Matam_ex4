#include "Witch.h"
#include "../../Players/Ninja.h"

Witch::Witch() : BattleCard(WITCH_LOOT, WITCH_DAMAGE, WITCH_FORCE) {}

std::string Witch::getName() const
{
	return "Witch";
}

int main()
{
	Witch witch;
	Ninja ninja("Jamy");
	std::cout << witch << std::endl;
	std::cout << ninja << std::endl;
	ninja.buff(10);
	witch.applyEncounter(ninja);
	std::cout << ninja.getCoins() << std::endl;
}