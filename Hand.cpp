/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Hand source file.
*/

#include "Hand.h"
#include "CardContainer.h"

void Hand::draw(Deck* d)
{
    this->add(d->deal());
}

void Hand::dealHand(Deck* d)
{
    int i = 0;
    for(i = 0; i < 5; i++)
        this->add(d->deal());
}