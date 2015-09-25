/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Deck source file.
*/
#include "Deck.h"
#include <string>
#include <ctime>
#include <cstdlib>

Deck::Deck()
{
	for (int i = 0; i < 11; i++) //11 camels
		add(&SuperDeck[6]);
	for (int i = 0; i < 10; i++) //10 leathers
		add(&SuperDeck[0]);
	for (int i = 0; i < 8; i++) //8 cloths
		add(&SuperDeck[1]);
	for (int i = 0; i < 8; i++) //8 spices
		add(&SuperDeck[2]);
	for (int i = 0; i < 6; i++) //6 silvers
		add(&SuperDeck[3]);
	for (int i = 0; i < 6; i++) //6 golds
		add(&SuperDeck[4]);
	for (int i = 0; i < 6; i++) //6 diamonds
		add(&SuperDeck[5]);
}

void Deck::shuffle()
{
    std::random_shuffle (cards.begin(), cards.end());
}

Card* Deck::deal()
{
    return this->removeCard(0);
}