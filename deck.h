//
// Created by timni on 10/4/2021.
//

#ifndef POKER_CARD_GAME_DECK_H
#define POKER_CARD_GAME_DECK_H

#include "card.h"
#include <vector>

class deck {

public:
    vector<card> deckOfCards;
    deck();
    void show();
    void shuffle();
    card getCard(int i);

};

#endif //POKER_CARD_GAME_DECK_H
