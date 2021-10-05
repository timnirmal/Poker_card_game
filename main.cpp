#include <iostream>

#include "deck.h"
#include "player.h"

//enum suit {clubs, heart, spades, diamond};
//♣0 ♥1 ♠2 ♦3

int player::nextId = 0;

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



    for (int j = 0; j < 5; j++) {
            Player[j].score();
        wcout<<endl;
    }

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