/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the CardContainer source file.
*/

#include "CardContainer.h"
#include <iostream> 
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

CardContainer::CardContainer()
{
}

CardContainer::~CardContainer()
{
}

void CardContainer::add(Card* card)
{
	cards.push_back(card);
    cardSort();
}

Card* CardContainer::access(int index)
{
	return cards.at(index);
}//end access

void CardContainer::printCards()
{
	for (unsigned int i = 0; i < cards.size(); i++)
		cout << i+1 << ") " << (cards.at(i))->getType() << endl;
}

Card* CardContainer::removeCard(int index)
{
    Card* temp = cards[index];
    cards.erase(cards.begin()+index);
    return temp;
}

Card* CardContainer::removeBack()
{
    Card* temp = cards.back();
    cards.pop_back();
    return temp;
}

void CardContainer::cardSort()
{
    std::sort(cards.begin(), cards.end(), PointerCompare());
}//end cardSort