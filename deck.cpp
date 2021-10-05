//
// Created by timni on 10/4/2021.
//

#include "deck.h"
#include <bits/stdc++.h>

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
            deckOfCards[k].setValue(j,R_suit);
            k++;
        }
    }

    cout<<"\nDeck Created\t";
    int length=sizeof(deckOfCards)/sizeof(int);
    cout<<length<<" \n";

}

void Deck::show() {
    for (int i=0; i< 52;i++){
        deckOfCards[i].display_card();
    }
    cout<<endl;
}

void Deck::shuffle() {
    //random_shuffle(deckOfCards[0],deckOfCards[length-1]);

    for (int i=0; i < 52; i++){
        deckOfCards[i].display_card();
    }
    //show();
}

