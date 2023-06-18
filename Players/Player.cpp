#include <iostream>
#include "../utilities.h"


Player::Player(std::string name) : m_name(name), m_level(START_LEVEL), m_coins(START_COINS), m_force(DEFAULT_FORCE)
{
	m_healthPoints = HealthPoints(DEFAULT_MAX_HP);
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	printPlayerDetails(os, player.getName(), player.getJob(), player.getLevel(), player.getForce(),player.getHp(), player.getCoins());
	return os;
}

void Player::levelUp()
{
	if (m_level < MAX_LEVEL)
	{
		m_level++;
	}
}

int Player::getLevel() const
{
	return m_level;
}

void Player::buff(const int force)
{
	if (force > 0)
	{
		m_force += force;
	}
}

void Player::heal(const int hp)
{
	if (hp > 0)
	{
		m_healthPoints += hp;
	}
}

void Player::damage(const int hp)
{
	if (hp > 0)
	{
		m_healthPoints -= hp;
	}
}

bool Player::isKnockedOut() const
{
	return m_healthPoints <= 0;
}

void Player::addCoins(const int coins)
{
	if (coins > 0)
	{
		m_coins += coins;
	}
}

bool Player::pay(const int coins)
{
	if (coins < 0)
	{
		return true;
	}
	if (m_coins - coins < 0)
	{
		return false;
	}
	m_coins -= coins;
	return true;
}

int Player::getAttackStrength() const
{
	return m_force + m_level;
}