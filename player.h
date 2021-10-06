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
    int playerHandScore;

public:
    vector<card> hand;
    int arrVal[15];
    // 0 A 2 3 4 5 6 7 8 9 10 J Q K A
    int arrSuit[4];

    player();
    void show();
    void shuffle();
    int getId();
    void getHand();
    card getHandCard(int i);
    int score();


    void setPlayerScore(int val);
    void setPlayerHandScore(int val);

    // In cases of duplocated we need to compare between
    card highCard();
    int OnePair();
    int TwoPair();
    int ThreePair();
    int straight();
    int FourPair();

    string getName();
};



#endif //POKER_CARD_GAME_PLAYER_H
