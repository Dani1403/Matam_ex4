#include "Card.h"

std::ostream& operator<<(std::ostream& os, const Card& card)
{
	card.printInfo(os);
	return os;
}

void Card::printInfo(std::ostream& os) const
{
	printCardDetails(os, this->getName());
	printEndOfCardDetails(os);
}