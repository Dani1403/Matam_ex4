#ifndef DRAGON_H
#define DRAGON_H

#include "BattleCard.h"
#include "../Players/Player.h"

const int DRAGON_FORCE = 25;
const int DRAGON_LOOT = 1000;
const int DRAGON_DAMAGE = DEFAULT_MAX_HP;

class Dragon : public BattleCard
{
public:
	Dragon();
	std::string getName() const override;
};

#endif // !DRAGON_H
