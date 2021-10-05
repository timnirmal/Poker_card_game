//
// Created by timni on 10/4/2021.
//

#ifndef POKER_CARD_GAME_DECK_H
#define POKER_CARD_GAME_DECK_H

#include "card.h"

class Deck : public card{
    card deckOfCards[52];

public:
    Deck();
    void show();
    void shuffle();

};

#endif //POKER_CARD_GAME_DECK_H
