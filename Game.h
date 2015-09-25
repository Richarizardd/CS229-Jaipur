/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Game header file.
*/

#ifndef _GAME_H
#define _GAME_H
#include "Bank.h"
#include "Player.h"
#include "Hand.h"
#include "Herd.h"
#include "Market.h"
#include "Deck.h"
#include "Card.h"
#include "Human.h"
#include "AI.h"
#include <vector>
#include <iostream>

class Game
{
	friend class Player;
    friend class Market;
    friend class AI; 
    Deck deck;
	Bank bank;//The bank that is to be used in that round
    Market market;
    CardContainer discard;
    Player** playerO = new Player*[2];

public:
	Game(); //Constructor that constructs the game, would construct the data members
    Game( const Game&);
	~Game(); //Destroys the game
	void setUpRound(); //Sets up the deck, market, discard pile, and bank to be used in that round
	void playRound(); //plays out that round
	void scoreRound(); //calculates the score for each player
	void clearRound();
    void setupMarket();
    void setupPlayers();
    bool gameOver() {return (playerO[1]->getSeals() >= 2 || playerO[0]->getSeals() >= 2);};
private:
	void takeCards(Player &);
	void takeCamels(Player &);
	void sellCards(Player &);
	bool isInvalidSell(std::vector<Card*>);
    bool endRound();
} ;
#endif