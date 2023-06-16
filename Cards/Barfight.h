#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

class Barfight : public Card
{
public:
	Barfight() = default;
	std::string getName() const override;
	void applyEncounter(Player& player) const override;
	
	static const int BARFIGHT_DAMAGE = 10;
};

#endif // !BARFIGHT_H
