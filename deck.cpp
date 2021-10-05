//
// Created by timni on 10/4/2021.
//

#include "deck.h"
#include <bits/stdc++.h>

#include <random>

//using namespace std;

Deck::Deck() {
    int k=0;
    suit R_suit;
    bool flag = 0;

    for (int i =0; i< 4; i++){
        for (int j=1; j<14; j++){
            switch (i)                // and a suit.
            {
                case 0: R_suit = clubs;     break;
                case 1: R_suit = heart;   break;
                case 2: R_suit = spades;     break;
                case 3: R_suit = diamond;    break;
            }
            card newCard;
            newCard.setValue(j,R_suit);
            deckOfCards.push_back(newCard);
        }
    }
    deckOfCards.resize(52);
    wcout<<"\nDeck Created\t\n";

}

void Deck::show() {
    //int k=0;
    for (auto & deckOfCard : deckOfCards){
        //k++;
        //wcout<<k<<" ";
        deckOfCard.display_card();
        //wcout<<"  ";
    }
}

void Deck::shuffle() {
    srand(time(0));
    for (int i=0; i < 52; i++){
        int randNum = rand() % 10 + 1;
        swap(deckOfCards[i],deckOfCards[randNum]);
    }
}

