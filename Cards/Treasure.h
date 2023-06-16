#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card
{
public:
	Treasure() = default;
	void applyEncounter(Player& player) const override;
	std::string getName() const override;

	static const int TREASURE_COINS = 10;
};

#endif // !TREASURE_H
