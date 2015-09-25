/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Market header file.
*/

#ifndef final_Market_h
#define final_Market_h

#include "Card.h"
#include "CardContainer.h"
#include "Deck.h"
#include <string>

class Market : public CardContainer
{
	friend class Player;
    friend class Deck;
    friend class Game;
    const int MAXSIZE = 5;
public:
    void fillMarket(Deck*);//deal cards from the deck to fill up the market
    //std::string toString();
    void replaceHand(CardContainer*);//add to Market from a hand, includes some rules
    bool isFull();
};
#endif