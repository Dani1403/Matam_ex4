#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card
{
	Treasure() : Card(0,0,TREASURE_COINS,0) {}
	void applyEncounter(Player& player) const override;
	std::string getName() const override;
	int getCoins() const override;
private:
	static const int TREASURE_COINS = 10;
};

#endif // !TREASURE_H
