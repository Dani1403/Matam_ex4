#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"

const int LEAVE = 0;
const int HEALTH = 1;
const int FORCE = 2;
const int HEALTH_POTION_COST = 5;
const int HEALTH_POTION = 1;
const int FORCE_BOOST_COST = 10;
const int FORCE_BOOST = 1;

class Merchant : public Card {
public:
	Merchant() : Card() {}
	void applyEncounter(Player& player) const override;
	std::string getName() const override;


};

#endif //MERCHANT_H