/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the AI header file.
*/

#include "Player.h"

#ifndef _AI_H
#define _AI_H

class AI: public Player
{
	friend class Game;
	friend int main(); //for testing purposes
	
public:
	AI();
	~AI(){};

private:
	//private data members
	int marketCardFreq[7];
    int handCardFreq[6];
    int combinedFreq[6];
    int maxFreq;
    int maxFreqIndex;
    std::string selectTemp;

	std::string getSellChoice();
    std::string getTakeChoice(Market &);
	std::string getTakeManyChoice(std::vector<Card*>, Market &);
	bool validReplace(Card* replace, std::vector<Card*> temp);
    int smartChoicev2(Market &);
    void calculateFreq(Market &);
    void resetFreq();

};
#endif