/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Token header file.
*/

#ifndef _TOKEN_H
#define _TOKEN_H
#include <string>

class Token
{
private:
	//data members
	std::string type; //could be a goods, camel, or bonus token. A seal of excellence is treated as a data member in player
	int index;// Automatic Banx index, as described in bank
	int value; 

public:
//Constructors
	Token(std::string typ, int val, int ind) {type = typ; value = val; index = ind;};
	Token(const Token & fromtoken) {type = fromtoken.getType(); value = fromtoken.getValue(); index = fromtoken.getIndex();};

//Accessors
	std::string getType() const {return type;};
	int getValue() const {return value;};
	int getIndex() const {return index;}; 
};
#endif