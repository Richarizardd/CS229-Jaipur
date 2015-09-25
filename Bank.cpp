/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Bank source file.
*/

#include "Bank.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm> 

using std::cout;
using std::endl;
using std::string;
using std::vector;

//Super Bank
Token Leather[] = {Token("Leather", 1, 0), Token("Leather", 2, 0), Token("Leather", 3, 0), Token("Leather", 4, 0)}; //index = 0
Token Cloth[] = {Token("Cloth", 1, 1), Token("Cloth", 2, 1), Token("Cloth", 3, 1), Token("Cloth", 5, 1)}; //index = 1
Token Spices[] = {Token("Spices", 1, 2), Token("Spices", 2, 2), Token("Spices", 3, 2), Token("Spices", 5, 2)}; //index = 2
Token Silver[] = {Token("Silver", 5, 3)}; //index = 3
Token Gold[] = {Token("Gold", 5, 4), Token("Gold", 6, 4)}; //index = 4
Token Diamond[] = {Token("Diamonds", 5, 5), Token("Diamonds", 7, 5)}; //index = 5
Token BT3[] = {Token("Bonus Token 3", 1, 6), Token("Bonus Token 3", 2, 6), Token("Bonus Token 3", 3, 6)}; //index = 6
Token BT4[] = {Token("Bonus Token 4", 4, 7), Token("Bonus Token 4", 5, 7), Token("Bonus Token 4", 6, 7)}; //index = 7
Token BT5[] = {Token("Bonus Token 5+", 8, 8), Token("Bonus Token 5+", 9, 8), Token("Bonus Token 5+", 10, 9)}; //index = 8


Bank::Bank()
{
	//Leather, index = 0
	for (int i = 0; i < 7; i++)
		bank[0].push_back(&Leather[0]);
	for (int i = 1; i < 4; i++)
		bank[0].push_back(&Leather[i]);

	//Cloth, index = 1
	for (int i = 0; i < 4; i++){
		bank[1].push_back(&Cloth[i]);
		bank[1].push_back(&Cloth[i]);
	}//end for

	//Spices, index = 2
	for (int i = 0; i < 4; i++){
		bank[2].push_back(&Spices[i]);
		bank[2].push_back(&Spices[i]);
	}//end for

	//Silver, index = 3
	for (int i = 0; i < 6; i++)
		bank[3].push_back(&Silver[0]);

	//Gold, index = 4
	for (int i = 0; i < 4; i++)
		bank[4].push_back(&Gold[0]);
	bank[4].push_back(&Gold[1]);
	bank[4].push_back(&Gold[1]);

	//Diamond, index = 5
	for (int i = 0; i < 4; i++)
		bank[5].push_back(&Diamond[0]);
	bank[5].push_back(&Diamond[1]);
	bank[5].push_back(&Diamond[1]);

	//Bonus Token 3, index = 6
	bank[6].push_back(&BT3[0]);
	bank[6].push_back(&BT3[0]);
	for (int i = 0; i < 3; i++)
		bank[6].push_back(&BT3[1]);
	bank[6].push_back(&BT3[2]);
	bank[6].push_back(&BT3[2]);

	//Bonus Token 4, index = 7
	for (int i = 0; i < 3; i++){
		bank[7].push_back(&BT4[i]);
		bank[7].push_back(&BT4[i]);
	}//end for

	//Bonus Token 5+, index = 8
	bank[8].push_back(&BT5[0]);
	bank[8].push_back(&BT5[0]);
	bank[8].push_back(&BT5[1]);
	bank[8].push_back(&BT5[2]);
	bank[8].push_back(&BT5[2]);
	
    std::random_shuffle (bank[6].begin(), bank[6].end());
    std::random_shuffle (bank[7].begin(), bank[7].end());
    std::random_shuffle (bank[8].begin(), bank[8].end());
}//end constructor

Bank::~Bank()
{
	for (int i = 0; i < 9; i++)
		bank[i].clear();
}//end destructor

Token* Bank::removeToken(string type)
{
	int index;
	if (type == "Leather")
		index = 0;
	else if (type == "Cloth")
		index = 1;
	else if (type == "Spices")
		index = 2;
	else if (type == "Silver")
		index = 3;
	else if (type == "Gold")
		index = 4;
	else if (type == "Diamonds")
		index = 5;
	else if (type == "Bonus Token 3")
		index = 6;
	else if (type == "Bonus Token 4")
		index = 7;
	else
		index = 8;

	Token* temp = bank[index].back();
	bank[index].pop_back();
	return temp;
}//end removeToken

bool Bank::isEmpty(string type)
{
	int index;
	if (type == "Leather")
		index = 0;
	else if (type == "Cloth")
		index = 1;
	else if (type == "Spices")
		index = 2;
	else if (type == "Silver")
		index = 3;
	else if (type == "Gold")
		index = 4;
	else if (type == "Diamonds")
		index = 5;
	else if (type == "Bonus Token 3")
		index = 6;
	else if (type == "Bonus Token 4")
		index = 7;
	else
		index = 8;

    if (bank[index].size() == 0)
        return true;
    return false;
}//end isEmpty()