#include "Mtmchkin.h"

std::queue < std::shared_ptr<Player> > createPlayers(const int numOfPlayers);
std::queue < std::shared_ptr<Card> > createDeck(const std::string& fileName);
bool getValidSize(int& size);



Mtmchkin::Mtmchkin(const std::string & fileName) : m_rounds(0)
{
	printStartGameMessage();
	m_deck = createDeck(fileName);
	printEnterTeamSizeMessage();
	while (!getValidSize(m_numOfActivePlayers))
	{
		printInvalidTeamSize();
		printEnterTeamSizeMessage();
	}
	m_activePlayers = createPlayers(m_numOfActivePlayers);
}

void Mtmchkin::playRound()
{
	printRoundStartMessage(++m_rounds);
	int removedPlayers = 0;
	for (int i = 0; i < m_numOfActivePlayers; i++)
	{
		printTurnStartMessage(m_activePlayers.front()->getName());
		m_deck.front()->applyEncounter(*m_activePlayers.front());
		m_deck.push(m_deck.front());
		m_deck.pop();
		if (m_activePlayers.front()->isKnockedOut())
		{
			removedPlayers++;
			m_losers.push(m_activePlayers.front());
		}
		else if (m_activePlayers.front()->getLevel() == MAX_LEVEL)
		{
			removedPlayers++;
			m_winners.push(m_activePlayers.front());
		}
		else
		{
			m_activePlayers.push(m_activePlayers.front());
			m_activePlayers.pop();
		}
		m_numOfActivePlayers -= removedPlayers;
		if (isGameOver())
		{
			printGameEndMessage();
		}
	}
}

void printPlayers(std::queue <std::shared_ptr<Player>> queueToPrint, int& startingRank)
{
	while (!queueToPrint.empty())
	{
		printPlayerLeaderBoard(++startingRank, *(queueToPrint.front()));
		queueToPrint.pop();
	}
}

void Mtmchkin::printLeaderBoard() const
{
	printLeaderBoardStartMessage();
	int startingRank = 0;
	printPlayers(m_winners, startingRank);
	printPlayers(m_activePlayers, startingRank);
	printPlayers(m_losers, startingRank);
}

bool Mtmchkin::isGameOver() const
{
	return !m_numOfActivePlayers;
}

int Mtmchkin::getNumberOfRounds() const
{
	return m_rounds;
}

std::queue < std::shared_ptr<Card> > createDeck(const std::string& fileName)
{
	std::queue < std::shared_ptr<Card> > tmpDeck;
	std::ifstream deck;
	deck.open(fileName);
	if (!deck.is_open())
	{
		throw DeckFileNotFound();
	}
	std::string cardType;
	int numOfCards = 0;
	while (std::getline(deck, cardType))
	{
		std::shared_ptr<Card> newCard(nullptr);
		if (cardType == "Dragon")
		{
			newCard = std::shared_ptr<Card>(new Dragon);
		}
		else if (cardType == "Witch")
		{
			newCard = std::shared_ptr<Card>(new Witch);
		}		
		else if (cardType == "Gremlin")
		{
			newCard = std::shared_ptr<Card>(new Gremlin);
		}		
		else if (cardType == "Mana")
		{
			newCard = std::shared_ptr<Card>(new Mana);
		}		
		else if (cardType == "Barfight")
		{
			newCard = std::shared_ptr<Card>(new Barfight);
		}		
		else if (cardType == "Well")
		{
			newCard = std::shared_ptr<Card>(new Well);
		}		
		else if (cardType == "Treasure")
		{
			newCard = std::shared_ptr<Card>(new Treasure);
		}
		else if (cardType == "Merchant")
		{
			newCard = std::shared_ptr<Card>(new Merchant);
		}
		else
		{
			throw DeckFileFormatError(numOfCards);
		}
		numOfCards++;
		tmpDeck.push(newCard);
		if (numOfCards < MIN_DECK_SIZE)
		{
			throw DeckFileInvalidSize();
		}
	}
	return tmpDeck;
}

bool isSizeValid(const int& size)
{
	return (size >= MIN_PLAYERS) && (size <= MAX_PLAYERS);
}

bool getValidSize(int& size)
{
	std::string tmpString;
	std::getline(std::cin, tmpString);
	if (tmpString.length() != 1)
	{
		return false;
	}
	try
	{
		size = stoi(tmpString);
	}
	catch (std::exception e)
	{
		return false;
	}
	return isSizeValid(size);
}

bool isLetter(char letterToCheck)
{
	return (letterToCheck >= 'a' && letterToCheck <= 'z') || (letterToCheck >= 'A' && letterToCheck <= 'Z');
}

bool isValidNameAndRole(std::string& nameAndRole)
{
	int index = 0;
	while (nameAndRole[index] != WORD_SEPARATOR)
	{
		if (!isLetter(nameAndRole[index]) || ++index > 15)
		{
			printInvalidName();
			return false;
		}
	}
	size_t pos = nameAndRole.find_first_of(WORD_SEPARATOR);
	std::string role = nameAndRole.substr(pos + 1);
	if (role != "Ninja" && role != "Warrior" && role != "Healer")
	{
		printInvalidClass();
		return false;
	}
	return true;
}

std::queue < std::shared_ptr<Player> > createPlayers(const int numOfPlayers)
{
	std::queue < std::shared_ptr<Player> > players;
	for (int player = 0; player < numOfPlayers; player++)
	{
		printInsertPlayerMessage();
		std::string nameAndRole;
		do 
		{
			std::getline(std::cin, nameAndRole);
		} while (!isValidNameAndRole(nameAndRole));
		size_t pos = nameAndRole.find_first_of(WORD_SEPARATOR);
		std::string name = nameAndRole.substr(0, pos);
		std::string role = nameAndRole.substr(pos + 1);
		std::shared_ptr<Player> newPlayer(nullptr);
		if (role == "Ninja")
		{
			newPlayer = std::shared_ptr<Player>(new Ninja(name));
		}
		else if (role == "Warrior")
		{
			newPlayer = std::shared_ptr<Player>(new Warrior(name));
		}
		else if (role == "Healer")
		{
			newPlayer = std::shared_ptr<Player>(new Healer(name));
		}
		players.push(newPlayer);
	}
	return players;
}
