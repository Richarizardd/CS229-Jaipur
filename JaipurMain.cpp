/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Jaipur Game main source file.
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
}