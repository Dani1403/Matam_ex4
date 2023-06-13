#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"

class Warrior : public Player
{
public:
	int getAttackStrength() const override;
	std::string getJob() const override;
};

#endif //WARRIOR_H
