/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Bank header file.
*/

#ifndef _BANK_H
#define _BANK_H
#include "Token.h"
#include <vector>
#include <string>

class Bank 
{
    friend class Game;
	//data members
	std::vector<Token*> bank[9]; //An array of (pointers to) List that contains pointers to the Tokens in the superbank

public:
	Bank(); //bank constructor
	~Bank(); //bank deconstructor
	bool isEmpty(std::string);
	Token* removeToken(std::string); //since every token posesses an "index value" in the bank, tokens can be easily removed from the bank by popping the list in that index of bank

private:
	void shuffleTokens(std::vector<Token*> *); //bonus tokens need to be shuffled (tokens 7-9)
};
#endif