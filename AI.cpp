/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the AI source file.
*/

#include "AI.h"
#include "CardContainer.h"
#include "Bank.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::vector;
using std::list;
using std::min;
 
AI::AI() : Player()
{
}

string AI::getSellChoice()
{
    vector<string> pickCards;
    string choice = "";
    for (int i =0; i < (int) selectTemp.length();i++){
        if (selectTemp[i] == '0')
            pickCards.push_back("Leather");
        else if (selectTemp[i] == '1')
            pickCards.push_back("Cloth");
        else if (selectTemp[i] == '2')
            pickCards.push_back("Spices");
        else if (selectTemp[i] == '3')
            pickCards.push_back("Silver");
        else if (selectTemp[i] == '4')
            pickCards.push_back("Gold");
        else if (selectTemp[i] == '5')
            pickCards.push_back("Diamonds");
    }

    if (pickCards.empty())
        pickCards.push_back(selectTemp);

    cout << "Supposed to sell: " << pickCards[0] << endl;

    int j = 0;
    for(int i = 0; i < hand.getSize(); i++)
    {
        if((hand.access(i))->getType() == pickCards[j]){
            choice += std::to_string(i + 1);
            j++;
        }
        if (selectTemp.length() == choice.length())
            break;
    }
    cout << choice << endl;
    pickCards.clear();
    return choice;
}

string AI::getTakeChoice(Market & market)
{
    vector<string> pickCards;
    string choice = "";
    for (int i =0; i < (int) selectTemp.length();i++)
    {
        if (selectTemp[i] == '0')
            pickCards.push_back("Leather");
        else if (selectTemp[i] == '1')
            pickCards.push_back("Cloth");
        else if (selectTemp[i] == '2')
            pickCards.push_back("Spices");
        else if (selectTemp[i] == '3')
            pickCards.push_back("Silver");
        else if (selectTemp[i] == '4')
            pickCards.push_back("Gold");
        else if (selectTemp[i] == '5')
            pickCards.push_back("Diamonds");
    }

    if (pickCards.empty())
        pickCards.push_back(selectTemp);
    
    cout << "Supposed to take: " << pickCards[0] << endl;

    int j = 0;
    for(int i = 0; i < market.getSize(); i++)
    {
        if((market.access(i))->getType() == pickCards[j])
        {
            choice += std::to_string(i + 1);
            j++;
        }
        if (selectTemp.length() == choice.length())
            break;
    }
    pickCards.clear();
    return choice;
}

string AI::getTakeManyChoice(vector<Card*> temp, Market &)
{
    string maxType;
    // Loop to figure out what card you have most of as to not sell it
    if (maxFreqIndex == 0)
        maxType = "Leather";
    else if (maxFreqIndex == 1)
        maxType = "Cloth";
    else if (maxFreqIndex == 2)
        maxType = "Spices";
    else if (maxFreqIndex == 3)
        maxType = "Silver";
    else if (maxFreqIndex == 4)
        maxType = "Gold";
    else
        maxType = "Diamonds";
    string replace = "";

    int camelTradeNum; // Now lets figure out how many camels we could trade in
    camelTradeNum = min((7 - hand.getSize()), ((int) temp.size()));
    camelTradeNum = min(camelTradeNum, (int) herd.getSize());
    for (int j = 0; j < camelTradeNum; j++) // and trade them in
    { 
        if (herd.getSize())
        {
            replace += '0';
            if (replace.length() == temp.size())
                break;
        }
    }
    // Then lets trade in other 'bad' cards
    for (int i = 0; i < hand.getSize(); i++)
    {
        if ((((hand.access(i))->getType() == "Leather") || ((hand.access(i))->getType() == "Cloth") || ((hand.access(i))->getType() == "Spices")) && replace.length() != temp.size())
        {
            if(validReplace(hand.access(i), temp))
                replace += std::to_string(i + 1);
            if (replace.length() == temp.size())
                break;
        }//end if
    }//end for
    if ((int) replace.length() != (int) temp.size()) 
    { //worst case
        for (int i = 0; i < hand.getSize(); i++) 
        {
            if (((hand.access(i))->getType() != "Leather") && ((hand.access(i))->getType() != "Cloth") && ((hand.access(i))->getType() != "Spices"))
                replace += std::to_string(i + 1);
            if (replace.length() == temp.size())
                break;
        }
    }
    return replace;
}

bool AI::validReplace(Card* replace, vector<Card*> temp)
{
    for(int i = 0; i < (int) temp.size(); i++)
    {
        if(temp.at(i)->getType() == replace->getType())
            return false;
    }
    return true;
}

//new shit

int AI::smartChoicev2(Market & market)
{
    resetFreq();
    calculateFreq(market);
    selectTemp = "";
    int maxTake = hand.getSize()+ herd.getSize() - handCardFreq[5] - handCardFreq[4] - handCardFreq[3];
    if (handCardFreq[5] > 1 ) 
    { // Sell Gems
        string temp (handCardFreq[5],'5');
        selectTemp = temp;
        return 1;
    }
    if (handCardFreq[4] > 1 )
    { // Sell Gold
        string temp (handCardFreq[4],'4');
        selectTemp = temp;
        return 1;
    }
    if ( handCardFreq[3] > 2)
    { // Sell silver
        string temp (handCardFreq[3],'3');
        selectTemp = temp;
        return 1;
    }
    if (marketCardFreq[5] > 0 && maxTake > 0)
    { //Take Diamnods
        string temp (min(marketCardFreq[5],maxTake),'5');
        selectTemp = temp;
        return 3;
    }
    
    if (marketCardFreq[4] > 0 && maxTake > 0 )
    { // Take Gold
        string temp (min(marketCardFreq[4], maxTake),'4');
        selectTemp = temp;
        return 3;
    }
        
    if (marketCardFreq[3] > 1 && maxTake > 0)
    { // Take Silver
        string temp (min(marketCardFreq[3], maxTake),'3');
        selectTemp = temp;
        return 3;
    }
        
    for (int i = 0; i < 3; i++) // Take cards if it will create advantage
    {
        int temp = maxTake;
        if (handCardFreq[i])
                maxTake = maxTake - handCardFreq[i];
        if (combinedFreq[i] > maxFreq + 1 && maxTake > 0)
        {
            int minni  = min(marketCardFreq[i], maxTake);
            char j = (char)(i + 48);
            string temp (minni, j);
            selectTemp = temp;
            return 3;
        }
        maxTake = temp;
    }//end for
    
    if ( (hand.getSize() >  6 && marketCardFreq[6] > 2) || (hand.getSize() < 3 && marketCardFreq[6]))
    {
        // Take camels
        return 2;
    }

    for (int i = 0; i < 4; i++) //Take cards for advantage
    {
        int temp = maxTake;
        if (handCardFreq[i])
            maxTake = maxTake - handCardFreq[i];
        if (((marketCardFreq[i] + handCardFreq[i]) > maxFreq) && maxTake > 0) {
            int minni  = min(marketCardFreq[i], maxTake);
            char j = (char)(i + 48);
            string temp (minni, j);
            selectTemp = temp;
            return 3;
        }
        maxTake = temp;
    }//end for
    
    int most = std::max(handCardFreq[2], handCardFreq[1]);
    most = std::max(most, handCardFreq[0]);
        
    for (int i = 2; i >= 0; i--) 
    { // sell off other cards
        if (handCardFreq[i] == most && most != 0 )
        {
            char j = (char)(i + 48);
            string temp (handCardFreq[i], j);
            cout<<"Temp is: "<< temp <<endl;
            selectTemp = temp;
            return 1;
            }
    }

    if (marketCardFreq[6] > 0)
    { // Then take camels
        return 2;
    }
    // Then just take something
    else
    {
        for (int i  = 0; i < 5; i++) {
            if (market.access(i)->getType() != "Camel") {
                cout<<"O12 Works"<<endl;
                selectTemp = market.access(i)->getType();
            }
        }
        return 3;
    }
}//end smartChoicev2


void AI::resetFreq(){
    memset(marketCardFreq, 0, sizeof(marketCardFreq));
    memset(handCardFreq, 0, sizeof(handCardFreq));
    memset(combinedFreq, 0, sizeof(combinedFreq));
    maxFreq = 0;
    maxFreqIndex = 0;
}

void AI::calculateFreq(Market & market)
{
    for (int i = 0; i < market.getSize(); i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if (*(market.access(i)) == hand.SuperDeck[j])
                marketCardFreq[j]++;
        }
        if ((market.access(i))->getType() == "Camel")
            marketCardFreq[6]++;
    }//end for

    for(int i = 0; i < hand.getSize(); i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if (*(hand.access(i)) == hand.SuperDeck[j])
                handCardFreq[j]++;
        }
    }//end for

    for(int i = 0; i < 6; i++)
        combinedFreq[i] = marketCardFreq[i] + handCardFreq[i];

    maxFreq = 0;
    for (int i = 0; i < 6; i++)
    {
        if (maxFreq < handCardFreq[i]) 
        {
            maxFreq = handCardFreq[i];
            maxFreqIndex = i;
        }
    }//end for
}//end calculateFreq;
