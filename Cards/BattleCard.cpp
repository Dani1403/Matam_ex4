#include "BattleCard.h"

void BattleCard::printInfo(std::ostream& os) const
{
	bool isDragon = (this->getName() == "Dragon");
	printCardDetails(os, this->getName());
	printMonsterDetails(os, m_force, m_damage, m_loot, isDragon);
	printEndOfCardDetails(os);
}

void BattleCard::applyEncounter(Player& player) const
{
	if (player.getAttackStrength() >= m_force)
	{
		player.levelUp();
		player.addCoins(m_loot);
		printWinBattle(player.getName(), this->getName());
	}
	else
	{
		player.damage(m_damage);
		printLossBattle(player.getName(), this->getName());
	}
}