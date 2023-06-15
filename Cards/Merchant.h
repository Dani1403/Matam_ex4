#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"

const int LEAVE = 0;
const int HEALTH = 1;
const int FORCE = 2;

class Merchant : public Card {
	Merchant() : Card() {}
	void applyEncounter(Player& player) const override;
	std::string getName() const override;
};

void applyChoice(Player& player, int choice);

#endif //MERCHANT_H