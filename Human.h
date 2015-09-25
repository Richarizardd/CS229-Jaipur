/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Human header file.
*/

#include "Player.h"

#ifndef _Human_H
#define _Human_H

class Human: public Player
{
	friend class Game;
	friend int main(); //for testing purposes

public:
	Human();
	~Human(){};

private:
	std::string getSellChoice();
    std::string getTakeChoice(Market &);
	std::string getTakeManyChoice(std::vector<Card*>, Market &);
	int smartChoicev2(Market &) {return 0;};
};
#endif