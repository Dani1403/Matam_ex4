#ifndef WITCH_H
#define WITCH_H

#include "BattleCard.h"

const int WITCH_LOOT = 3;
const int WITCH_FORCE = 12;
const int WITCH_DAMAGE = 10;

class Witch : public BattleCard
{
public:
	Witch();
	std::string getName() const override;
};

#endif
