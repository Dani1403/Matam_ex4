#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "utilities.h"
#include "Exception.h"

#include <string>
#include <fstream>
#include <ostream>
#include <queue>
#include <stack>
#include <memory>

#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"

#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/Mana.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"

#include "Cards/BattleCards/BattleCard.h"
#include "Cards/BattleCards/Dragon.h"
#include "Cards/BattleCards/Gremlin.h"
#include "Cards/BattleCards/Witch.h"

const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 6;
const int MIN_DECK_SIZE = 5;
const char WORD_SEPARATOR = ' ';
    
class Mtmchkin {

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string& fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::queue < std::shared_ptr<Card> > m_deck;
    std::queue < std::shared_ptr<Player> > m_activePlayers;
    std::queue < std::shared_ptr <Player> > m_winners;
    std::queue < std::shared_ptr <Player> > m_losers;
    int m_rounds;
    int m_numOfActivePlayers;
};


#endif /* MTMCHKIN_H_ */