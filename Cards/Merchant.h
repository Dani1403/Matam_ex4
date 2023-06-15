#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"

const int LEAVE = 0;
const int HEALTH = 1;
const int FORCE = 2;

class Merchant : public Card {
	Merchant();
	void applyEncounter(Player& player) const;
	std::string getName() const;
	void printInfo() const;
};

void applyChoice(Player& player, int choice);

#endif //MERCHANT_H