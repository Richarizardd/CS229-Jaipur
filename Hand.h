/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Hand header file.
*/
#ifndef final_Hand_h
#define final_Hand_h

#include "Card.h"
#include "Deck.h"

class Hand : public CardContainer
{
    friend class Player;
    friend class Human;
    const int MAXSIZE = 7;

public:
    void draw(Deck*);//takes a card from another cardcontainer and adds it to hand
    void dealHand(Deck*);//deals a new hand from the deck
};
#endif
