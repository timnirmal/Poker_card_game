//
// Created by timni on 10/4/2021.
//

#ifndef POKER_CARD_GAME_DECK_H
#define POKER_CARD_GAME_DECK_H

#include "card.h"
#include <vector>

class Deck : public card{
    vector<card> deckOfCards;

public:
    Deck();
    void show();
    void shuffle();

};

#endif //POKER_CARD_GAME_DECK_H
