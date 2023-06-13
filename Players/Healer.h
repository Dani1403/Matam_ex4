#ifndef HEALER_H
#define HEALER_H

#include "Player.h"

class Healer : public Player
{
public:
	Healer(const std::string& name);
	void heal(const int hp) override;
	std::string getJob() const override;
};

#endif //HEALER_H
