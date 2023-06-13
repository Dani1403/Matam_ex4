#include "Ninja.h"

Ninja::Ninja(const std::string& name) : Player(name) {}

void Ninja::addCoins(const int coins) {
	Player::addCoins(coins * 2);
}

std::string Ninja::getJob() const {
	return "Ninja";
}