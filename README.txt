/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the README.txt file.
*/

Hello there!

Welcome to our Jaipur program. We hope you have as much fun grading it as we did coding it up :)

A few things:

0)
    In order to compile using our makefile, simply type "make" into the terminal.
    In order to run the executable, simply type "make run" into the terminal after compiling.
    In order to clean, simply type "make clean" into the terminal.

1)
    Our "AI" is a *REALLY* 'smart' AI (AKA EXTRA CREDIT WAHOOOO!!!!). 
    To use it you MUST enter "AI1" for the Player 1 name or "AI2" for the Player 2 name when prompted. 
    Curious about our AI decision making tree? The heirachy can be found in our file AI.cpp in our smartChoicev2 function. 
    Basically we statistically determined expected points per move given certain circumstances and programmed that into a 20+ member decision tree algorithm.

2)

    Our JaipurTest.cpp consists of 3 main tests:

-We construct a game of AI1 vs. AI2. The game is completely automated.
The AIs pick random menu choices, then use validity checking to narrow down
their moves to valid moves that will lead to the end of a game.
The AIs successfully play an entire game (either 2 or 3 rounds until one wins 2 seals).

    ***Here you also must enter AI1 for Player 1 and AI2 for Player2***

- We have test cases for our Bank.

- We have test cases for our CardContainer and all subclasses (Deck, Market, Hand).

- AND so many more tests-- just check it out!!!


3)

If you have any questions grading, please feel free to email atsai11@jhu.edu or call at 408-528-5809
If you want to take off points for any of the terrible humor in this README, call David Feldman at (512) 789-5354
