/**
# NAME: Andrew Tsai, Richard Chen, Calvin Pollard, David Feldman
# COURSE: 600.120 Section 4
# DATE: 15 Dec 2014
# ASSIGNMENT: hw7b
# PHONE: (408) 528-5809
# BB LOGIN/JHED ID: atsai11, rchen40, cpollar4, dfeldma9
# EMAIL: atsai11@jhu.edu, rchen40@jhu.edu, cpollar4@jhu.edu, dfeldma9@jhu.edu
# COMMENTS: This is the Game source file.
*/

#include "Game.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;

Game::Game()
{
    string name = "";
    for(int i = 1; i <= 2; i++)
    {
        cout << "Please enter a name for player " << i << " (type AI1 or AI2 for cpu player):" << endl;
        cin >> name;
        if(name == "AI1" || name == "AI2" || name == "AI")
            playerO[i % 2] = new AI();
        else
            playerO[i % 2] = new Human();
        playerO[i % 2]->name = name;
    }
}

Game::~Game() //Destroys the game
{
    for(int i = 0; i < 2; i++)
        delete playerO[i];
    delete [] playerO;
} 

Game::Game(const Game& old) 
{
    string oldName1 = old.playerO[1]->getName();
    string oldName2 = old.playerO[0]->getName();
    string oldNames[2] = {oldName2, oldName1};

    for(int i = 1; i <= 2; i++)
    {
        if(oldNames[i % 2] == "AI1" || oldNames[i % 2] == "AI2" || oldNames[i % 2] == "AI")
            playerO[i % 2] = new AI();
        else
            playerO[i % 2] = new Human();
        playerO[i % 2]->name = oldNames[i % 2];
        playerO[i % 2]->seals = old.playerO[i % 2]->getSeals();
    }
}

void Game::setUpRound()
{
	setupMarket();
	cout << "This is the market." << endl;
	market.printCards();
	setupPlayers();
} //

void Game::setupMarket()
{
    for (int i=0; i<3; i++)
        market.add(deck.deal());
    deck.shuffle();
    market.fillMarket(&deck);
    deck.printCards();
}

void Game::setupPlayers()
{
    for(int i = 1; i <= 2; i++)
    {
        playerO[i % 2]->hand.dealHand(&deck);
        playerO[i % 2]->moveHerd();
        cout << "Player " << i << " hand." << endl;
        playerO[i % 2]->hand.printCards();
        cout << "Player " << i << " herd." << endl;
        playerO[i % 2]->herd.printCards();
    }
}

void Game::playRound(){
	int choice = 0;
    int game = 1;
	string str;
	bool validTurn = false;

	while (!endRound()){
		cout << endl << "********************TURN MENU********************" << endl;
		cout << "Size of deck is: " << deck.getSize() << endl;
		cout << "Market is:" << endl;
		market.printCards();
		cout << endl << playerO[game % 2]->name << "'s Hand:" << endl;
		(playerO[game % 2]->hand).printCards();
		cout << "You have " << (playerO[game%2]->herd).getSize() << " camels in your herd." << endl;
		while(!validTurn)
        {    
            string hchoice;
            cout << endl << "What would " << playerO[game%2]->name << " like to do?" << endl;
    		cout << "1) Sell Cards" << endl;
    		cout << "2) Take All Camels" << endl;
    		cout << "3) Take Cards" << endl;
            
            bool isAI = false;
            if(playerO[game % 2]->name == "AI1" || playerO[game%2]->name == "AI2")
            {
                choice = playerO[game % 2]->smartChoicev2(market);
                isAI = true;
            }
            else
    		  cin >> hchoice;

            bool control = true;
            while (control && !isAI)
            {
                if (hchoice == "1" || hchoice == "2" || hchoice == "3")
                {
                    control = false;
                    choice = std::stoi(hchoice);
                }
                else
                {
                    cout << "Invalid choice! Please try again" <<endl;
                    cin >> hchoice;
                }
            }

    		switch(choice)
    		{
    			case 1: validTurn = playerO[game%2]->canSell(); break;
    			case 2: validTurn = playerO[game%2]->canTakeCamels(market); break;
    			case 3: validTurn = true; break;
    		}
        }
        cout << "\033[2J\033[1;1H" << endl; // Clean screen text ;)
		switch(choice)
        {
            case 1: str = playerO[game % 2]->getSellChoice(); validTurn = playerO[game % 2]->sellCards(str, discard, bank); break;
            case 2: validTurn = playerO[game % 2]->takeCamels(market); market.fillMarket(&deck); break;
            case 3: str = playerO[game % 2]->getTakeChoice(market); validTurn = playerO[game % 2]->takeCards(str, market); market.fillMarket(&deck); break;
        }
        validTurn = false;
        game++;
	}//end while
    scoreRound();
}

bool Game::endRound()
{
    if (!deck.getSize())
        return true;

    int numempty = 0;
    for (int i = 0; i < 6; i++)
    {
        if (bank.bank[i].size() == 0)
            numempty++;
    }
    if (numempty > 2) 
        return true;
    else 
        return false;
}

void Game::scoreRound()
{ 
    cout << "\033[2J\033[1;1H" << endl; // Clean screen text ;)
    cout << "********************FINAL ROUND RESULTS********************"<<endl<<endl;
    
    int player1_pts = 0;
    int player2_pts = 0;
    
    //add up all points for players
    
    for (int i = 0; i< (int)playerO[1]->wallet.size(); i++)
        player1_pts = player1_pts + playerO[1]->wallet[i]->getValue();
    for (int i = 0; i< (int) playerO[0]->wallet.size(); i++)
        player2_pts = player2_pts + playerO[0]->wallet[i]->getValue();
    
    // assign camel points
    char which = '0';
    if (playerO[1]->herd.getSize() > playerO[0]->herd.getSize())
    {
        player1_pts = player1_pts + 5;
        which = '1';
    }
    else if (playerO[1]->herd.getSize() == playerO[0]->herd.getSize())
    {
    }
    else 
    {
        player2_pts = player2_pts + 5;
        which = '2';
    }

    // prints everything out
    // Player 1 wallet
    cout << endl<<playerO[1]->name <<"'s final wallet is:" << endl; //prints your wallet
    for (int i = 0; i < (int) playerO[1]->wallet.size(); i++)
        cout << (playerO[1]->wallet.at(i))->getType() << ": " << (playerO[1]->wallet.at(i))->getValue() << endl;
    // Player 2 wallet
    cout << endl<<playerO[0]->name <<"'s final wallet is:" << endl; //prints your wallet
    for (int i = 0; i < (int) playerO[0]->wallet.size(); i++)
        cout << (playerO[0]->wallet.at(i))->getType() << ": " << (playerO[0]->wallet.at(i))->getValue() << endl;
    
    if (which == '1')
    cout << endl << endl << playerO[1]->name <<" recieves 5 points from having the most camel cards.";
    if (which == '2')
        cout << endl << endl << playerO[0]->name <<" recieves 5 points from having the most camel cards at the end of the round";
    
    cout<< endl << endl << playerO[1]->name << " finishes round with "<<  player1_pts << " points.";
     cout<< endl << endl << playerO[0]->name << " finishes round with "<<  player2_pts << " points."<< endl << endl;
    
    if (player1_pts > player2_pts) 
    {
        playerO[1]->seals++;
        cout << endl << endl << playerO[1]->name <<" WINS ROUND!!!!" <<endl;
    }
    else if (player2_pts == player1_pts)
    {
    }
    else 
    {
        playerO[0]->seals++;
        cout<<endl<<endl<<playerO[0]->name << " WINS ROUND!!!!" <<endl;
    }
    cout << "********************FINAL ROUND RESULTS********************" << endl << endl << endl;

    if(playerO[1]->seals > 1 || playerO[0]->seals > 1)
    {
        cout << "********************FINAL GAME RESULTS********************" << endl;
        if(playerO[1]->seals > 1)
            cout << playerO[1]->name << " has won the entire game!" << endl << endl;
        if(playerO[0]->seals > 1)
            cout << playerO[0]->name << " has won the entire game!" << endl << endl;
        cout << "The final token score is:" << endl;
        cout << playerO[1]->name << ": " << playerO[1]->seals << endl;
        cout << playerO[0]->name << ": " << playerO[0]->seals << endl;
    }
}
