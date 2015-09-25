/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Player header file.
*/

#include "CardContainer.h"
#include "Token.h"
#include "Hand.h"
#include "Market.h"
#include "Herd.h"
#include "Bank.h"
#include <vector>
#include <list>
#include <string>
//#include "Herd"

#ifndef _Player_H
#define _Player_H

class Player
{
	friend class Game;
	friend class AITest;

	//data members
protected:
	std::string name;
	Hand hand;
	Herd herd;
	std::vector<Token*> wallet; //do we really need this? Can this just be an int?
	int seals;
	std::string choice;

public:
	Player();
	virtual ~Player(){};

	int getSeals() const {return seals;};
    std::string getName() const {return name;};
	bool canSell();
	bool canTakeCamels(Market &);

    void resetPlayer();
	bool sellCards(std::string, CardContainer &, Bank &); //pure virtual
    bool takeCards(std::string, Market &); //pure virtual
    bool takeMany(std::string, std::vector<Card*>, Market & market); //pure virtual
    virtual std::string getSellChoice() = 0;
    virtual std::string getTakeChoice(Market &) = 0;
    virtual std::string getTakeManyChoice(std::vector<Card*>, Market &) = 0;
    virtual int smartChoicev2(Market &) = 0;
    bool isInvalidChar(std::string);
    bool isInvalidChoice(std::string, int);
	bool isInvalidSell(std::vector<Card*>);
	bool takeCamels(Market &);	
    void moveHerd();
    bool takeOne(std::vector<Card*>);
};
#endif