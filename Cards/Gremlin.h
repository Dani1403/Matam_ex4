#ifndef GREMLIN_H
#define GREMLIN_H

#include "BattleCard.h"

const int GREMLIN_LOOT = 3;
const int GREMLIN_FORCE = 7;
const int GREMLIN_DAMAGE = 10;

class Gremlin : public BattleCard
{
public:
	Gremlin();
	std::string getName() const override;
};

#endif