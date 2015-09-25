/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Player source file.
*/

#include "Player.h"
#include "CardContainer.h"
#include "Bank.h"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::vector;
using std::list;
 
Player::Player()
{
	name = "Default Name";
    seals = 0;
}

bool Player::canSell()
{
    int diamonds = 0, silvers = 0, golds = 0;
    for(int i = 0; i < hand.getSize(); i++)
    {
        if(*(hand.access(i)) == hand.SuperDeck[0] || *(hand.access(i)) == hand.SuperDeck[1] || *(hand.access(i)) == hand.SuperDeck[2])
            return true;
        if(*(hand.access(i)) == hand.SuperDeck[3])
            silvers++;
        if(*(hand.access(i)) == hand.SuperDeck[4])
            golds++;
        if(*(hand.access(i)) == hand.SuperDeck[5])
            diamonds++;
    }

    if(silvers < 2 && golds < 2 && diamonds < 2)
    {
        cout << "To sell silvers, golds, or diamonds, you must have at least 2." << endl;
        return false;
    }

    if(hand.getSize() == 0)
    {
        cout << "You do not have any cards to sell." << endl;
        return false;
    }
    return true;
}

bool Player::canTakeCamels(Market & market)
{
    if(*(market.access(0)) == hand.SuperDeck[6])
        return true;
    else
    {
        cout << "There are no camels in the market." << endl;
        return false;
    }
}

bool Player::isInvalidChar(string choice)
{
	for(unsigned int i = 0; i < choice.length(); i++)
    {
		cout << "Character: " << choice[i] << endl;
    	if(!isdigit(choice[i]))
            return true;
    }//end for
    return false;
}//end isInvalidChar

bool Player::isInvalidChoice(string choice, int hand_size)
{
    if((int)choice.length() > hand_size) //if you tried selecting more cards than in your hand
        return true;

    int min, next;
    for(int i = 0; i < (int) choice.length(); i++) //checking numerical order or repeats
    {
        min = choice[i] - '0';
        for(int j = i + 1; j < (int) choice.length(); j++)
        {    
            next = choice[j] - '0';
            if(next < min)
            {
                cout << "Please enter choice in increasing numerical order." << endl;
                return true;
            }
            else if(next == min)
            {
                cout << "Please do not select the same card more than once." << endl;
                return true;
            }
        }
    }

    for(int i = 0; i < (int)choice.length(); i++)
    {
    	if((choice[i] - '0') > hand_size)
            return true;
        for(int j = i + 1; j < (int)choice.length(); j++)
            if(choice[i] == choice[j])
                return true;
    }//end for
    return false;
}//end isInvalidChoice

bool Player::isInvalidSell(vector<Card*> temp)
{
	if (temp.size() == 1)
    {
		if ((temp[0])->getType() == "Silver" || (temp[0])->getType() == "Gold" || (temp[0])->getType() == "Diamonds")
			return true;
		return false;
	}//end if
	
	for (unsigned int i = 0; i < temp.size() - 1; i++)
    {
		if ((temp[i])->getType() != (temp[i+1])->getType())
			return true;
	}//end for
	return false;
}//end 

bool Player::takeCamels(Market & market)
{
	int count = 0;
	for(int i = 0; i < market.getSize(); i++)
	{
		if(market.access(i)->getType() == "Camel")
		{
			hand.add(market.removeCard(i));
			count++;
			i--;
		}
	}
	if(count == 0)
	{
		cout << "There are no camels in the market. Please select another option." << endl;
		return false;		
	}
	moveHerd();
	cout << "The size of your herd is now: " << herd.getSize() << endl << endl;
	return true;
}

void Player::moveHerd()
{
    for (int i=0; i<hand.getSize(); i++) {
        if (((hand.cards[i])->type)=="Camel") 
        {
            herd.add(hand.removeCard(i));
            i--;
        }
    }
}

bool Player::takeOne(vector<Card *> temp)
{
    hand.add(temp[0]);
    cout<< "Sucess. Your hand is now:" <<endl;
    hand.printCards();
    moveHerd();
    return true;
}

bool Player::sellCards(string choice, CardContainer & discard, Bank & bank)
{
    if (choice == "0")
        return false;
    for (unsigned int i = 0; i < choice.size(); i++)
    { //discards cards sold from the hand, pushes tokens to to the user's wallet
        string type = (hand.access(choice[i] - '0' - i - 1))->getType();
        if (!bank.isEmpty(type))
            wallet.push_back(bank.removeToken(type));
        discard.add(hand.removeCard((choice[i] - '0' - i - 1)));
    }//end for

    if (choice.size() >= 3)
    {
        switch(choice.size())
        {
            case 5: case 6: case 7:
            {
                if (!bank.isEmpty("Bonus Token 5+"))
                {
                    wallet.push_back(bank.removeToken("Bonus Token 5+"));
                    break;
                }//end if
            }//end case 5
            case 4:
            {
                if (!bank.isEmpty("Bonus Token 4"))
                {
                    wallet.push_back(bank.removeToken("Bonus Token 4"));
                    break;
                }//end if
            }//end case 4
            default:
            {
                if (!bank.isEmpty("Bonus Token 3"))
                    wallet.push_back(bank.removeToken("Bonus Token 3"));
                break;
            }//end default
        }//switch
    }//end if
    
    cout << endl;
    cout << "This is in your wallet: " << endl; //prints your walletmake
    for (int i = 0; i < (int) wallet.size(); i++)
        cout << (wallet.at(i))->getType() << ": " << (wallet.at(i))->getValue() << endl;
    return true;
    
}//end sellCards

bool Player::takeCards(string str, Market & market) 
{
    string many;
    if(str == "0")
        return false;
    std::vector<Card*> temp;
    // use someone elses card remover because I don't get it

    for (unsigned int i = 0; i < str.size(); i++)
        temp.push_back(market.removeCard(str[i] - '0' - i - 1));
    
    // either take one or take many
    if (hand.getSize() < 7 && temp.size() == 1)
        return takeOne(temp);
    else
    {
        many = getTakeManyChoice(temp, market);
        return takeMany(many, temp, market);
    }
}//end takeCards

bool Player::takeMany(string choice, std::vector<Card*> temp_in, Market & market)
{
    std::sort(choice.begin(), choice.end());
// vector of cards to trade back in
    std::vector<Card*> temp_out; 
    //remove the other cards from hand and put them in temp_out
    int cc = 0;
    for (unsigned int i = 0; i < choice.length(); i++)
    {
        if(choice[i] == '0')
            temp_out.push_back((herd.removeBack()));
        else
        {
            temp_out.push_back(hand.removeCard(choice[i] - '0' - cc - 1));
            cc++;
        }
    }
    // put cards into hand
    int size = (int) temp_in.size();
    for(int i = 0; i < size; i++)
        hand.add(temp_in[i]);

    while (!temp_out.empty())
    {
        market.add(temp_out.back());
        temp_out.pop_back();
    }

    // end it
    cout<< "Success. Your hand is now:" <<endl;
    moveHerd();
    hand.printCards();
    return true;
}
