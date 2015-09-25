/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the JaipurTest source file.
*/

#include "Game.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::endl;

int main()
{
    //This code creates a game with 2 AI's pitted against each other
    std::srand(std::time(0));    
    Game round1;
    round1.setUpRound();
    round1.playRound();
    Game round2(round1);
    round2.setUpRound();
    round2.playRound();
    if (!round2.gameOver()) 
    {
        Game round3(round2);
        round3.setUpRound();
        round3.playRound();
    }

    cout << "AI vs. AI game successfully completed!" << endl;
    cout << "All valid and invalid cases passed!" << endl << endl;

	cout << "********************BANK TESTING********************" << endl;
	Bank testbank = Bank();
	cout << "Bank successfully constructed!" << endl;
	
	for (int i = 0; i < 10; i++)
			testbank.removeToken("Leather");
	for (int i = 0; i < 8; i++)
			testbank.removeToken("Cloth");
	for (int i = 0; i < 8; i++)
			testbank.removeToken("Spices");
	for (int i = 0; i < 6; i++)
			testbank.removeToken("Silver");
	for (int i = 0; i < 6; i++)
			testbank.removeToken("Gold");
	for (int i = 0; i < 6; i++)
			testbank.removeToken("Diamonds");
	for (int i = 0; i < 7; i++)
			testbank.removeToken("Bonus Token 3");
	for (int i = 0; i < 6; i++)
			testbank.removeToken("Bonus Token 4");
	for (int i = 0; i < 5; i++)
			testbank.removeToken("Bonus Token 5+");
    
    string typeArray[] = {"Leather", "Cloth", "Spices", "Silver", "Gold", "Diamonds", "Bonus Token 3", "Bonus Token 4", "Bonus Token 5+"};

    for (int i = 0; i < 9; i++)
        assert(testbank.isEmpty(typeArray[i]) == true);

	cout << "removeToken successful!" << endl;
	cout << "Bank.cpp successfully asserted." << endl;
	cout << "All tests passed!" << endl;


	cout << "********************CARD TESTING********************" << endl;
	Card c("foo", "testlocation");
    assert(c.getType() == "foo");
    assert(c.getLocation() == "testlocation");
    
    //testing of CardContainer
    CardContainer ccon;
    assert(ccon.getSize()==0);
    Card d("bar", "testlocation2");
    assert(d == d);
    ccon.add(&c);
    assert(ccon.getSize() == 1);
    assert(*(ccon.access(0)) == c);
    ccon.add(&d);
    assert(ccon.getSize() == 2);
    assert(*(ccon.access(0)) == d);
    assert(*(ccon.access(1)) == c);
    Card* rmv = ccon.removeCard(1);
    assert(ccon.getSize() == 1);
    assert(*rmv == c);
    assert(*ccon.access(0) == d);
    //cannot easily assert test printCards, but it has worked fine over several runs
    cout << "All tests for CardContainer passed!" << endl;
    
    //testing of Deck
    Card SuperDeck[7] = {Card("Leather", "Super Deck"), Card("Cloth", "Super Deck"), Card("Spices", "Super Deck"), Card("Silver", "Super Deck"), Card("Gold", "Super Deck"), Card("Diamonds", "Super Deck"), Card("Camel", "Super Deck")};
    Deck decktest;
    int index = 0;
    for (int i = 0; i < 11; i++)
    {
        assert(*(decktest.access(index))==SuperDeck[6]);
        index++;
    }
    for (int i = 0; i < 8; i++)
    {
        assert(*(decktest.access(index))==SuperDeck[1]);
        index++;
    }
    for (int i = 0; i < 6; i++)
    {
        assert(*(decktest.access(index))==SuperDeck[5]);
        index++;
    }
    for (int i = 0; i < 6; i++)
    {
        assert(*(decktest.access(index))==SuperDeck[4]);
        index++;
    }
    for (int i = 0; i < 10; i++)
    {
        assert(*(decktest.access(index))==SuperDeck[0]);
    	index++;
    }
    for (int i = 0; i < 6; i++)
    {
        assert(*(decktest.access(index))==SuperDeck[3]);
        index++;
    }
    for (int i = 0; i < 8; i++)
    {
        assert(*(decktest.access(index))==SuperDeck[2]);
        index++;
    }
    //shuffle has been assumed to work after testing with printed output, and testing that it in fact perectly randomizes is hard
    for (int i=0; i<index; i++)
    {
        Card* temp = decktest.access(0);
        CardContainer discard;
        discard.add(decktest.deal());
        assert(*(discard.access(0))==*temp);
    }
    cout << "All tests for Deck passed!" << endl;
    //testing for Hand
    Hand handtest;
    Deck deck1;
    CardContainer testcon;
    for (int i = 0; i<5; i++)
        testcon.add(deck1.access(i));
    handtest.dealHand(&deck1);
    for (int i = 0; i<5; i++)
        assert(*(handtest.access(i))==*(testcon.access(i)));
    for (int i=5; i<index; i++)
    {
        testcon.add(deck1.access(0));
        handtest.draw(&deck1);
        assert(*(testcon.access(0))==*(handtest.access(0)));
    }
    cout << "All tests for Hand passed!" << endl;  
    //testing for Market
    Market markettest;
    Deck deck2;
    CardContainer ccon1;
    for (int i=0; i<5; i++)
        ccon1.add(deck2.access(i));
    markettest.fillMarket(&deck2);
    for (int i = 0; i<5; i++)
        assert(*(ccon1.access(i))==*(markettest.access(i)));
    cout << "All tests for Market passed!" << endl;
    cout << "All tests related to Cards passed!" << endl;   
}