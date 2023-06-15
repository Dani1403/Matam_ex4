#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

class Barfight : public Card
{
	Barfight() : Card(0,BARFIGHT_DAMAGE,0,0) {}
	std::string getName() const override;
	void applyEncounter(Player& player) const override;
	int getDamage() const override;
private:
	static const int BARFIGHT_DAMAGE = 10;
};

#endif // !BARFIGHT_H
