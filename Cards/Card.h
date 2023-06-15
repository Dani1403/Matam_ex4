//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"



class Card {
public:
    /*
     * C'tor of Card class
     *
     * @return
     *      A new instance of Card.
    */
    Card(int force = 0, int damage = 0, int coins = 0, int heal = 0);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;

    /*
    * Getters
    */
    virtual std::string getName() const = 0;
    virtual int getForce() const = 0;
    virtual int getDamage() const = 0;
    virtual int getCoins() const = 0;
    virtual int getHeal() const = 0;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

protected:
    int m_force;
    int m_damage;
    int m_coins;
    int m_heal;
};

std::ostream& operator<<(std::ostream& os, const Card& card);


#endif //EX2_Card_H