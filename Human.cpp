/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Human source file.
*/
#include "Human.h"
#include "CardContainer.h"
#include "Bank.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::vector;
using std::list;
using std::remove;

Human::Human() : Player()
{
}

string Human::getSellChoice()
{
    bool buggedcase = true;
    bool invalidsell;
    do{
        bool invalidchoice;
        do{
            bool invalidchar;
            do{
                cout << endl << "What cards would you like to sell?" << endl;
                hand.printCards();
                cout << "0) Return to turn menu." << endl;

                if (buggedcase)
                    cin.ignore();
                getline(cin, choice);
                cout << "\033[2J\033[1;1H" << endl;

                choice.erase(std::remove(choice.begin(), choice.end(), ' '), choice.end());
                cout << "Your choice was: " << choice << endl;

                if(choice == "0")
                    return choice;

                invalidchar = isInvalidChar(choice);
                if (invalidchar){
                    buggedcase = false;
                    cout << "You entered an invalid character. Please try again." << endl;;
                }//end if
            }while (invalidchar);

            invalidchoice = isInvalidChoice(choice, hand.getSize());

            if (invalidchoice)
            {
                buggedcase = false;
                cout << "You entered an invalid choice. Please try again." << endl;
            }//end if
        }while (invalidchoice);

        vector<Card*> temp; //pushes all of the cards corresponding to user input to a temporary vector
        for (unsigned int i = 0; i < choice.size(); i++)
            temp.push_back(hand.access((choice[i] - '0' - 1)));
        
        cout << endl << "You have selected:" << endl;
        for (unsigned int i = 0; i < temp.size(); i++)
            cout << (temp[i])->getType() << endl;
        cout << endl;
        
        invalidsell = isInvalidSell(temp); //checks the vector to see if the selected cards to be sold are valid
        if (invalidsell)
        { //if cards are invalid, loops
            buggedcase = false;
            cout << "You have entered an invalid selection. Please try again. " << endl;
        }//end if
    }while (invalidsell);
    return choice;
}

string Human::getTakeChoice(Market & market)
{
    bool buggedcase = true;
    bool invalidchoice = true;
    do{
        bool invalidchar;
        do{
            cout<<endl << "Please select the cards that you would like to take:"<< endl;
            market.printCards();

            if (buggedcase)
                cin.ignore();
            getline(cin, choice);
            cout << "\033[2J\033[1;1H" << endl;
            choice.erase(std::remove(choice.begin(), choice.end(), ' '), choice.end());
            cout << "Your choice was: " << choice << endl;

            invalidchar = isInvalidChar(choice);
            if (invalidchar)
            {
                buggedcase = false;
                cout << "You entered an invalid character. Please try again." << endl;;
            }//end if
        }while (invalidchar);

        invalidchoice = isInvalidChoice(choice, market.getSize());

        if (invalidchoice)
        {
            buggedcase = false;
            cout << "You entered an invalid choice. Please try again." << endl;
        }//end if
    }while(invalidchoice);
    return choice;
}

string Human::getTakeManyChoice(vector<Card*> temp, Market &)
{
    int end = 0;
    // validity checking loop to sell cards -- must turn in same number that will recieve.
    while (end == 0) 
    {
        cout<< "Please select the *same* number of cards as you took that you would like to remove from your hand or herd. (Hand may not exceed 7 cards):"<<endl;
        if (herd.getSize())
            cout<< "0) Camel from Herd"<< " (you have "<< herd.getSize()<< " , enter \"0\" for as many as you want to trade in)"<< endl;
        hand.printCards();
        
    // basically a paste of the input reader above
        
        string in;
        std::getline (std::cin,in);
        cout << "\033[2J\033[1;1H" << endl;
        // keeping track of camels
        int cam_count = 0;
        char* newchoice = new char(100); // c sting
        int i = 0;
        int j = 1;
        // remove all non-numbers, put into newchoice

        for ( std::string::iterator it=in.begin(); it!=in.end(); ++it) 
        {
            // here is the difference. code to deal with camels.
            if (*it == '0' ) 
                cam_count++;
            if (isdigit(*it)) 
            {
                newchoice[i] = *it;
                i++;
            }
            j++;
        }
        newchoice[i] = '\0'; // terminate c  string
        choice = newchoice; // c++ string

        bool in_range = true;
        for(int k = 0; k < i; k++)
        {
            if((int) newchoice[i] > hand.getSize())
                in_range = false;
        }

        if (in_range == true && choice.length() == temp.size() && hand.getSize() + cam_count <=7)
            end = 1;
        else
            cout<< "Invalid trade-in. Please try again."<<endl;
        delete newchoice;
    }
    return choice;
}
