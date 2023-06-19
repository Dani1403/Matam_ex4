#ifndef BATTLECARD_H
#define BATTLECARD_H

#include "Card.h"

class BattleCard : public Card
{
public:
	BattleCard(const int loot, const int damage, const int force) : m_loot(loot), m_force(force), m_damage(damage) {}
	/*
	* Getters
	*/
	int getLoot() { return m_loot; }
	int getDamage() { return m_damage; }
	int getForce() { return m_force; }

	/*
	* BattleCard Functions
	*/
	void printInfo(std::ostream& os) const override;
	void applyEncounter(Player& player) const override;
protected:
	int m_loot;
	int m_damage;
	int m_force;
};

#endif