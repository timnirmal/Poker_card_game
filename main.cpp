#include <iostream>
#include <windows.h>

#include "deck.h"
#include "player.h"

//enum suit {clubs, heart, spades, diamond};
//♣0 ♥1 ♠2 ♦3

bool tie = false;
vector<int> tiePositions;   //Clear at each round

int player::nextId = 0;
bool finish = 0;
bool effectEnable = 1;

int checkHighCard(card c1, card c2, int p1, int p2) {
    wcout << "\nChecking High Card "<< endl;
    c1.display_card();
    wcout <<endl;
    c2.display_card();

    if (c1.getValueA() > c2.getValueA()){
        return p1;
    }
    else if (c1.getValueA() < c2.getValueA()){
        return p2;
    }
    else {
        tie = true;
        tiePositions.push_back(p1);
        tiePositions.push_back(p2);
    }
}

int checkOnePair (int c1, int c2, int p1, int p2) {
    if (c1 == 1) c1 = 14;
    if (c2 == 1) c2 = 14;

    wcout << "\nChecking One Pair "<< endl;
    wcout << c1;
    wcout <<endl;
    wcout << c2;

    if (c1 > c2){
        return p1;
    }
    else if (c1 < c2){
        return p2;
    }
    else {
        tie = true;
        tiePositions.push_back(p1);
        tiePositions.push_back(p2);
    }
}

//Text Animations
void textLoader(string txt){
    vector<char> LoaderTXT(txt.begin(), txt.end());
    for (const char &c: LoaderTXT) {
        //Switch Based on Effects Settings
        if (effectEnable == true) {
            wcout << "G";
            Sleep(30);
            wcout<< "\b ";
            Sleep(40);
        }
        std::wcout << c;
    }
}

int main() {

    card cards;

    //cards.setValue(2,heart);
    //cards.display_card();

    int numPlayers = 3;
    int numRounds = 10;

    ////////////////////////////////////////////////  Create Player
    wcout << endl << "Create Players\n";

    vector<player> Player;  //Player[0] is the dealer
    Player.resize(numPlayers + 1);

    wcout << endl << "Create Players Done\n";

    for (int i = 0; i < 2; i++) {
        ////////////////////////////////////////////////  Deck Create and Shuffle
        deck deckOfCards;

        deckOfCards.show();

        for (int j=0; j<=i; j++){
            deckOfCards.shuffle();
        }
        wcout << endl;

        wcout << endl;
        deckOfCards.show();
        wcout << endl;
        wcout << endl;

        ////////////////////////////////////////////////  Card Distribution
        //erase first two values
        deckOfCards.deckOfCards.erase(deckOfCards.deckOfCards.begin());
        deckOfCards.deckOfCards.erase(deckOfCards.deckOfCards.begin());

        wcout << endl;
        deckOfCards.show();
        wcout << endl;

        for (int i = 0; i < 4; i++) {
            card newCard;
            //wcout << i.getName().c_str();
            //copy 5 card to hand of each player
            for (int j = 0; j < 5; j++) {
                newCard.setValue(deckOfCards.deckOfCards.begin()->getValue(),
                                 deckOfCards.deckOfCards.begin()->getSuit());
                Player[i].hand[j] = newCard;
                deckOfCards.deckOfCards.erase(deckOfCards.deckOfCards.begin());
            }
        }

        wcout << endl;
        Player[0].hand.back().display_card();
        Player[0].getHandCard(0).display_card();
        wcout << endl;

        wcout << "displaycard\n\n";

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                Player[i].hand[j].display_card();
            }
            wcout << endl;
        }

        wcout << endl;

        ////////////////////////////////////////////////  Calculate Scores
        //Calculating Score of Each Player
        int highCardCount = 0;      //Count if all are high cards.
        int tempScore;              // to Keep player score of each round of each player
        int arrScore[4]; //4 Players

        for (int j = 0; j < 4; j++) {
            tempScore = Player[j].score();

            Player[j].setPlayerHandScore(tempScore);
            arrScore[j] = tempScore;

            if (tempScore == 0) {
                highCardCount++;
            }

            wcout << "\nScore = " << tempScore;
            wcout << "\tHigh Card = ";
            Player[j].highCard().display_card();
            wcout << endl;
        }

        wcout << endl;

        for (int i = 0; i < 4; i++) {
            wcout << arrScore[i] << " ";
        }

        int tempHighScore = arrScore[0];
        int winnerPosition = 0;
        int tempCount = 0;

        for (int i = 0; i < 3; i++) {
            if (tempHighScore < arrScore[i]) {
                tempHighScore = arrScore[i];
                winnerPosition = i;
            }
        }
        wcout << endl << tempHighScore << " " << winnerPosition;

        //Check if two people have The Highest Val
        for (int i = 0; i < 4; i++) {
            if (arrScore[i] == tempHighScore && winnerPosition != i) {
                //wcout << "\nDuplicate";
                switch (tempHighScore) {
                    case 0:
                    case 6:
                        // 5 Cards have same color and Highest card win among players
                        winnerPosition = checkHighCard(Player[winnerPosition].highCard(), Player[i].highCard(),
                                                       winnerPosition, i);
                        wcout << "\n\nWinner(0) = " << winnerPosition;
                        break;
                    case 2:
                        winnerPosition = checkOnePair(Player[winnerPosition].OnePair(), Player[i].OnePair(),
                                                      winnerPosition,
                                                      i);
                        wcout << "\n\nWinner(2) = " << winnerPosition;
                        break;
                    case 3:
                        winnerPosition = checkOnePair(Player[winnerPosition].TwoPair(), Player[i].TwoPair(),
                                                      winnerPosition,
                                                      i);
                        //The highest Pair comes to here
                        wcout << "\n\nWinner(3) = " << winnerPosition;
                        break;
                    case 4:
                        winnerPosition = checkOnePair(Player[winnerPosition].ThreePair(), Player[i].ThreePair(),
                                                      winnerPosition, i);
                        wcout << "\n\nWinner(4) = " << winnerPosition;
                        break;
                    case 5:
                    case 9:
                        winnerPosition = checkOnePair(Player[winnerPosition].straight(), Player[i].straight(),
                                                      winnerPosition, i);
                        wcout << "\n\nWinner(5/9) = " << winnerPosition;
                        break;
                    case 7:
                        // Game Logic For Full House tie
                        // First Higher Triples wins
                        // If that gets equal then highest Pair Wins
                        // If that also get equal both get points
                        winnerPosition = checkOnePair(Player[winnerPosition].ThreePair(), Player[i].ThreePair(),
                                                      winnerPosition, i);
                        if (tie == true) {
                            tie = false;
                            winnerPosition = checkOnePair(Player[winnerPosition].TwoPair(), Player[i].TwoPair(),
                                                          winnerPosition, i);
                        }
                        wcout << "\n\nWinner(7) = " << winnerPosition;
                        break;
                    case 8:
                        winnerPosition = checkOnePair(Player[winnerPosition].FourPair(), Player[i].FourPair(),
                                                      winnerPosition, i);
                        wcout << "\n\nWinner(8) = " << winnerPosition;
                        break;
                }
            }
        }

        // Now we have checked who wins
        // If there are two winners and that also calculated.
        // But if that also get tie then that part is to be added. (Scores will be given to both.)

        /*
            winnerPosition is the position of winner in Player array
            Player[winnerPosition] is winner
            tempHighScore is his score

            Others score can be taken by playerHandScore

         */


        wcout << endl;
        wcout << "Winner is " << winnerPosition << "   Score : " << tempHighScore;
        wcout << "\n\nOthers Score \n";
        for (int i = 0; i < 4; i++) {
            //tempScore = Player[i].getPlayerHandScore();
            //Player[i].addPlayerScore(tempScore);
            wcout << "Player " << i << "   Score : " << tempScore << "   Total Score : " << Player[i].getPlayerScore()
                  << endl;
        }

        ////////////////////////////////////////////////  Each Hand Score Calculation Done & Winner is Chosen
        // But the score is not the actual value goes into Score Board.

        //Players cards are hiden
        //Dealers cards are visible

        // Probability
        // User Can Leave round if he wants
        //





        tiePositions.clear();
        tie = false;
    }

    wcout << "\n";
    wcout << "$$$$$$$\\            $$\\                                  $$$$$$\\                                    \n";
    wcout << "$$  __$$\\           $$ |                                $$  __$$\\                                   \n";
    wcout << "$$ |  $$ | $$$$$$\\  $$ |  $$\\  $$$$$$\\   $$$$$$\\        $$ /  \\__| $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\  \n";
    wcout << "$$$$$$$  |$$  __$$\\ $$ | $$  |$$  __$$\\ $$  __$$\\       $$ |$$$$\\  \\____$$\\ $$  _$$  _$$\\ $$  __$$\\ \n";
    wcout << "$$  ____/ $$ /  $$ |$$$$$$  / $$$$$$$$ |$$ |  \\__|      $$ |\\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |\n";
    wcout << "$$ |      $$ |  $$ |$$  _$$<  $$   ____|$$ |            $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|\n";
    wcout << "$$ |      \\$$$$$$  |$$ | \\$$\\ \\$$$$$$$\\ $$ |            \\$$$$$$  |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$\\ \n";
    wcout << "\\__|       \\______/ \\__|  \\__| \\_______|\\__|             \\______/  \\_______|\\__| \\__| \\__| \\_______|\n";
    wcout << "                                                                                                    \n";
    wcout << "                                                                                                    \n";
    wcout << "                                                                                                    ";

    wcout << "\nPoker Game";


    int inpNum;

    while (true) {
        if (finish) {    //Check termination conditions
            return 0;
        }

        ////Main menu
        wcout << "1. Start" << endl;
        wcout << "2. How to Play" << endl;
        wcout << "3. Settings" << endl;
        wcout << "4. Exit" << endl;

        wcout << "\nEnter number : ";
        wcin >> inpNum;
        wcout << endl;

        //Start
        if (inpNum == 1) {
            //puzzleGen();
        }
            //How to Play
        else if (inpNum == 2) {

        }
            //Settings
        else if (inpNum == 3) {
            system("cls");
            wcout<<endl;
            wcout << "\t * * * Settings * * *" << endl;
            wcout<< "\nCurrent Settings : \n\tEffects : "<<effectEnable;
            //cout <<  "\n\tLevel : "<<Level<<endl;

            char inp;

            wcout<< "\n\nChange Effect (y/n) : ";
            cin>>inp;
            if(inp=='y' || inp=='Y'){
                effectEnable = !effectEnable;
            }else{
                effectEnable = effectEnable;
            }

            cout<<"Changed Effects : "<<effectEnable<<endl<<endl;
        }
            //Exit
        else if (inpNum == 4) {
            system("cls");
            textLoader("\nExiting.....");
            wcout<<endl<<endl;
            wcout<< "\tThank you for Playing";
            wcout<<endl<<endl;
            finish = true;
        }
    }



    return 0;
}

//Value
//2-10 & Jack, Queen, King, and Aces
//Shape Spade, Diamond, Heart, and Club
//Color

//Dealer shuffles the cards
//removes the first two cards in the pack
//distributes five cards (hands) for each player including himself
//The players’ hands are not visible but the dealer cards are visible