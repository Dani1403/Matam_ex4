#include "Card.h"

Card::Card(int force, int damage, int coins, int heal) :
	m_force(force), m_damage(damage), m_coins(coins), m_heal(heal)
{}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
	printCardDetails(os, card.getName());
	printEndOfCardDetails(os);
}