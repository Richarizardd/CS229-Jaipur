/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Deck header file.
*/

#ifndef final_Deck_h
#define final_Deck_h
#include "Card.h"
#include "CardContainer.h"

class Deck : public CardContainer 
{
    //no extra data
public:
	Deck();
    void shuffle();//randomizes the deck
    Card* deal();//take a sigle card from the top of the deck
};
#endif