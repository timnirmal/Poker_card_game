#include <iostream>

#include "deck.h"
#include "player.h"

//enum suit {clubs, heart, spades, diamond};
//♣0 ♥1 ♠2 ♦3

bool tie = false;
vector<int> tiePositions;   //Clear at each round

int player::nextId = 0;

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


int main() {

    card cards;

    //cards.setValue(2,heart);
    //cards.display_card();

    deck deckOfCards;

    deckOfCards.show();
    deckOfCards.shuffle();
    wcout << endl;

    wcout << endl;
    deckOfCards.show();
    wcout << endl;

    //vector<card> deckOCards;

    deckOfCards.getCard(51).display_card();
    wcout << endl;

    int numPlayers = 3;
    int numRounds = 10;

    wcout<<endl<<"Create Players\n";

    vector <player> Player;  //Player[0] is the dealer
    Player.resize(numPlayers+1);

    wcout<<endl<<"Create Players Done\n";

    //erase first two values
    deckOfCards.deckOfCards.erase(deckOfCards.deckOfCards.begin());
    deckOfCards.deckOfCards.erase(deckOfCards.deckOfCards.begin());

    wcout << endl;
    deckOfCards.show();
    wcout << endl;

    for (int i=0;i<4;i++) {
        card newCard;
        //wcout << i.getName().c_str();
        //copy 5 card to hand of each player
        for (int j=0; j<5; j++) {
            newCard.setValue(deckOfCards.deckOfCards.begin()->getValue(),deckOfCards.deckOfCards.begin()->getSuit());
            Player[i].hand[j] = newCard;
            deckOfCards.deckOfCards.erase(deckOfCards.deckOfCards.begin());
        }
    }

    wcout<<endl;
    Player[0].hand.back().display_card();
    Player[0].getHandCard(0).display_card();
    wcout<<endl;

    wcout<<"displaycard\n\n";

    for(int i=0; i<4; i++) {
        for (int j = 0; j < 5; j++) {
            Player[i].hand[j].display_card();
        }
        wcout<<endl;
    }

    wcout<<endl;


    //Calculating Score of Each Player
    int highCardCount = 0;      //Count if all are high cards.
    int tempScore;              // to Keep player score of each round of each player
    int arrScore[4]; //4 Players

    for (int j = 0; j < 4; j++) {
        tempScore = Player[j].score();

        Player[j].setPlayerHandScore(tempScore);
        arrScore[j] = tempScore;

        if(tempScore == 0){
            highCardCount++;
        }

        wcout<< "\nScore = "<< tempScore;
        wcout<< "\tHigh Card = "; Player[j].highCard().display_card();
        wcout<<endl;
    }

    wcout<<endl;

    for (int i = 0; i < 4; i++) {
        wcout << arrScore[i] << " ";
    }

    int tempHighScore = arrScore[0];
    int winnerPosition = 0;
    int tempCount = 0;

    for (int i = 0; i < 3; i++) {
        if (tempHighScore < arrScore [i]){
            tempHighScore = arrScore[i];
            winnerPosition = i;
        }
    }
    wcout <<endl<< tempHighScore << " " << winnerPosition;

    //Check if two people have The Highest Val
    for (int i = 0; i < 4; i++) {
        if (arrScore[i] == tempHighScore && winnerPosition != i){
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
                    winnerPosition = checkOnePair(Player[winnerPosition].OnePair(), Player[i].OnePair(), winnerPosition,
                                                  i);
                    wcout << "\n\nWinner(2) = " << winnerPosition;
                    break;
                case 3:
                    winnerPosition = checkOnePair(Player[winnerPosition].TwoPair(), Player[i].TwoPair(), winnerPosition,
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

    /*
    wcout << endl;
    for (int i=0; i<4; i++) {
        wcout << Player[1].arrSuit[i] << " ";
    }
    wcout << endl;
    for (int i=1; i<15; i++) {
        wcout << Player[1].arrVal[i] << " ";
    }
    */

    // Calculating Winner of this round.



    //Players cards are hiden
    //Dealers cards are visible

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