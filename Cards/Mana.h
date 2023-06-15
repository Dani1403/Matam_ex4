#ifndef MANA_H
#define MANA_H

#include "Card.h"

class Mana : public Card {
	Mana() : Card(0,0,0,MANA_HEAL) {};
	void applyEncounter(Player& player) const override;
	std::string getName() const override;
	int getHeal() const override;
private:
	static const int MANA_HEAL = 10;
};

#endif //MANA_H