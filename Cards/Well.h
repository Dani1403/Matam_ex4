#ifndef WELL_H
#define WELL_H

#include "Card.h"

class Well : public Card
{
	Well() : Card(0, WELL_DAMAGE, 0, 0) {};
	std::string getName() const override;
	void applyEncounter(Player& player) const override;
	int getDamage() const override;
private:
	static const int WELL_DAMAGE = 10;
};

#endif //WELL_H
