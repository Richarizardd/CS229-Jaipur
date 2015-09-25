/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Card header file.
*/

#ifndef _Card_H
#define _Card_H
#include <string>

class Card
{
    friend class Player;
    friend class Human;
	std::string type;
	std::string location;

public:
	//Constructors
     Card(std::string typ, std::string loc) {type = typ; location = loc;};  // constructor with default params
     Card(const Card & fromcard): type(NULL), location(NULL) {type = fromcard.getType(); location = fromcard.getLocation();};   // copy constructor for copying object
 
	//Accessors / equals operator
    std::string getType() const {return type;} ; // inline definition
    std::string getLocation() const {return location;} ; // inline definition	    
    bool operator==(const Card & other) const {if (other.getType() == this->getType()) return true; else return false;} ; //inline
    std::string toString() const {return type;} ; //inlined
    bool operator ==(const Card& c){if((type==c.type)&&(location==c.location)) return true; else return false;};

//Modifier 
    void newLocation(std::string loc = "Deck") {location = loc;}; 
};
#endif