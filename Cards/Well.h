#ifndef WELL_H
#define WELL_H

#include "Card.h"

class Well : public Card
{
	Well() = default;
	std::string getName() const override;
	void applyEncounter(Player& player) const override;

	static const int WELL_DAMAGE = 10;
};

#endif //WELL_H
