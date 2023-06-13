#include "Ninja.h"

void Ninja::addCoins(const int coins) {
	Player::addCoins(coins * 2);
}

std::string Ninja::getJob() const {
	return "Ninja";
}