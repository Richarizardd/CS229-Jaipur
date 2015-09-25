/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the CardContainer header file.
*/

#ifndef _CARDCONTAINER_H
#define _CARDCONTAINER_H

#include "Card.h" 
#include <vector>
#include <iostream> 
#include <cstdlib>
#include <algorithm>

class CardContainer 
{
protected:
	std::vector<Card *> cards;

public:
    Card SuperDeck[7] = {Card("Leather", "Super Deck"), Card("Cloth", "Super Deck"), Card("Spices", "Super Deck"), Card("Silver", "Super Deck"), Card("Gold", "Super Deck"), Card("Diamonds", "Super Deck"), Card("Camel", "Super Deck")};
	CardContainer();
    ~CardContainer();
    int getSize() {return (int) this->cards.size();};
	Card* access(int); 
	void printCards();
    void add(Card*);
    Card* removeCard(int);
    Card* removeBack(); //removes and returns the last card of the container
    
private:
	void cardSort();
	struct PointerCompare
    {
    	bool operator()(const Card* a, Card* b)
    	{
    		return a->getType() < b->getType();
    	}//struct
    };
} ; 
#endif