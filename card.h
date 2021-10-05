//
// Created by timni on 10/4/2021.
//

enum suit {clubs, heart, spades, diamond};
//♣0 ♥1 ♠2 ♦3

#include <vector>
#include <string>

using namespace std;

#ifndef POKER_CARD_GAME_CARD_H
#define POKER_CARD_GAME_CARD_H

class card {

private:
    int val; //( A = 1, J = 11, Q = 12, K = 13)
    suit s;
public:
    //card():val(0),s(0);
    void display_card();
    void display_card_without_symbols();
    void setValue(int v,suit st);
    int getValue();
    suit getSuit();
    int getSuitValue();
};


#endif //POKER_CARD_GAME_CARD_H
