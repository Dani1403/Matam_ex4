//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX4_Card_H
#define EX4_Card_H

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
    Card() = default;


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

    virtual void printInfo(std::ostream& os) const;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

};

std::ostream& operator<<(std::ostream& os, const Card& card);


#endif //EX4_Card_H