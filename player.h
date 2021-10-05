//
// Created by timni on 10/5/2021.
//

#ifndef POKER_CARD_GAME_PLAYER_H
#define POKER_CARD_GAME_PLAYER_H

#include "deck.h"

using namespace std;

class player {
    static int nextId;
    int playerId;
    string playerName;
    int playerScore;

public:
    vector<card> hand;

    player();
    void show();
    void shuffle();
    int getId();
    void getHand();
    card getHandCard(int i);
    void score();

    string getName();
};



#endif //POKER_CARD_GAME_PLAYER_H
