#include <iostream>

#include "deck.h"

//enum suit {clubs, heart, spades, diamond};
//♣0 ♥1 ♠2 ♦3


int main() {

    card cards;

    //cards.setValue(2,heart);
    //cards.display_card();

    Deck decks;

    decks.show();
    decks.show();
    cout<<endl;
    decks.show();
    cout<<endl;
    decks.shuffle();

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