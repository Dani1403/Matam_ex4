#ifndef MANA_H
#define MANA_H

#include "Card.h"

class Mana : public Card {
public:
	Mana() = default;
	void applyEncounter(Player& player) const override;
	std::string getName() const override;

	static const int MANA_HEAL = 10;
};

#endif //MANA_H