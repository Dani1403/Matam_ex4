#ifndef NINJA_H
#define NINJA_H

#include "Player.h"

class Ninja : public Player
{
public:
	void addCoins(const int coins) override;
	std::string getJob() const override;
};

#endif //NINJA_H