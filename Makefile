# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the makefile for JaipurTest

CC=g++
CCFLAGS = -std=c++11 -pedantic -Wall -Wextra -O -g
GCOV= -fprofile-arcs -ftest-coverage

all: JaipurMain

JaipurMain: JaipurMain.cpp
	$(CC) $(CCFLAGS) Bank.cpp Player.cpp Game.cpp CardContainer.cpp Deck.cpp Market.cpp Hand.cpp Human.cpp AI.cpp JaipurMain.cpp -o JaipurMain

JaipurTest: JaipurTest.cpp
	$(CC) $(CCFLAGS) Bank.cpp Player.cpp Game.cpp CardContainer.cpp Deck.cpp Market.cpp Hand.cpp Human.cpp AI.cpp JaipurTest.cpp -o JaipurTest

run: JaipurMain
	./JaipurMain

clean:
	rm -i JaipurMain JaipurTest *.gcov *.gcda *.gcno