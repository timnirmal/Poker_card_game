//
// Created by timni on 10/4/2021.
//

#include "deck.h"
#include <bits/stdc++.h>
#include <windows.h>
#include <unistd.h>

#include <random>

//using namespace std;

deck::deck() {
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
}

void deck::show() {
    for (auto & deckOfCard : deckOfCards){
        deckOfCard.display_card();
    }
}

void deck::shuffle() {
    srand(time(0));
    for (int i=0; i < 52; i++){
        int randNum = rand() % 10 + 1;
        deckOfCards[i].display_card();
        wcout << " ";
        deckOfCards[randNum].display_card();
        wcout << "\t";
        wprintf(L"\u25AE");
        wcout << "   ";
        Sleep(10);
        wcout << "\r";
        wcout << "\b\b";
        swap(deckOfCards[i],deckOfCards[randNum]);
    }
}

card deck::getCard(int i) {
    return deckOfCards[i];
}

