#ifndef MANA_H
#define MANA_H

#include "Card.h"

class Mana : public Card {
	Mana();
	void applyEncounter(Player& player) const;
	std::string getName() const;
	void printInfo() const;

private :
	static const int HP_TO_HEAL = 10;
};

#endif //MANA_H