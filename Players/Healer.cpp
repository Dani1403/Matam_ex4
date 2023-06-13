#include "Healer.h"

Healer::Healer(const std::string& name) : Player(name) {}

void Healer::heal(const int hp) {
	Player::heal(hp * 2);
}

std::string Healer::getJob() const {
	return "Healer";
}