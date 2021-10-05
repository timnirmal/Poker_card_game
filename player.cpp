//
// Created by timni on 10/5/2021.
//

#include <iostream>
#include "player.h"

using namespace std;

player::player() {
    wcout << "Me Called \n";
    playerId = nextId++;
    playerName = "Tim";
    playerScore = 0;
    hand.resize(5);
}

string player::getName() {
    return playerName;
}

int player::getId() {
    wcout << playerId;
    return playerId;
}

void player::getHand() {
    for (int i=0; i< 5; i++){
        hand[i].display_card();
    }
}

card player::getHandCard(int i) {
    hand[i].display_card();
    return hand[i];
}

void player::score() {
    vector<card> hand_Copy;

    //for (int i=0; i< 5; i++){
      //  hand_Copy[i] = hand [i];
    //}

// enum suit {clubs, heart, spades, diamond};
// ♣0 ♥1 ♠2 ♦3

    //Taking values and suites to two arrays
    hand[0].getValue();
    hand[0].getSuit();

    int arrVal[14];
    int arrSuit[4];


    for (int i=0; i<4; i++) {
        arrSuit[i] = 0;
    }

    for (int i=0; i<14; i++) {
        arrVal[i] = 0;
    }

    for (int i=0; i<5; i++) {
        switch (hand[i].getSuitValue()) {
            case 0: arrSuit[0]++; break;
            case 1: arrSuit[1]++; break;
            case 2: arrSuit[2]++; break;
            case 3: arrSuit[3]++; break;
        }

        switch (hand[i].getValue()) {
            case 1: wcout << " 1 & 14 " <<hand[i].getValue()<<endl;arrSuit[1]++; arrSuit[14]++; break;
            case 2: wcout << " 2 " <<hand[i].getValue()<<endl;arrSuit[2]++; break;
            case 3: wcout << " 3 " <<hand[i].getValue()<<endl;arrSuit[3]++; break;
            case 4: wcout << " 4 " <<hand[i].getValue()<<endl;arrSuit[4]++; break;
            case 5: wcout << " 5 " <<hand[i].getValue()<<endl;arrSuit[5]++; break;
            case 6: wcout << " 6 " <<hand[i].getValue()<<endl;arrSuit[6]++; break;
            case 7: wcout << " 7 " <<hand[i].getValue()<<endl;arrSuit[7]++; break;
            case 8: wcout << " 8 " <<hand[i].getValue()<<endl;arrSuit[8]++; break;
            case 9: wcout << " 9 " <<hand[i].getValue()<<endl;arrSuit[9]++; break;
            case 10:wcout << " 10 " <<hand[i].getValue()<<endl; arrSuit[10]++; break;
            case 11:wcout << " 11 " <<hand[i].getValue()<<endl; arrSuit[11]++; break;
            case 12:wcout << " 12 " <<hand[i].getValue()<<endl; arrSuit[12]++; break;
            case 13:wcout << " 13 " <<hand[i].getValue()<<endl; arrSuit[13]++; break;
        }
    }

    wcout << endl<<endl;

    for (int i=0; i<4; i++) {
        wcout << arrSuit[i] << " ";
    }
    wcout << endl;
    for (int i=0; i<14; i++) {
        wcout << arrVal[i] << " ";
    }

    int highCard, onePair, twoPair, threeKind, straight, flush, fullHouse, fourKind, straightFlush;
    highCard = onePair = twoPair = threeKind = straight = flush = fullHouse = fourKind = straightFlush = 0;
    //Straight Flush - All have same suite

    for (int i=0; i<4; i++) {
        if ( arrSuit[i] == 5){
            straightFlush = 1;
        }
        else if ((arrSuit[0] + arrSuit[2]) == 5 || (arrSuit[1] + arrSuit[3]) == 5 ){
            flush = 1;
        }
    }

    for (int i=0; i<14; i++) {
        if ( arrVal[i] == 4){
            fourKind = 1;
        }
        else if ( arrVal[i] == 3){
            threeKind = 1;
        }
        else if ( arrVal[i] == 2){
            onePair++;
        }
    }

    /*
    if (straightFlush == 1) {
        straightFlush;
    }
    if (onePair == 1 && threeKind == 1){

    }
    else if () {

    }*/
}

//1. High card: None of the following combinations and highest card value is considered (2-2, 3-3, …, 10-10, Jack-11, Queen-12, King-13, Aces-14)
//2. One pair: two cards with the same value.
// 3. Two pairs: two times two cards of same value.
// 4. Three of a kind: Three cards with same value.
// 5. Straight: five cards with values in sequence (Ace can also be seen as one, but we must choose:
//The values "Ace-2-3-4-5" form a sequence, like the values "10 - Jack - Queen - King - Ace ", but, for example, values" King - Ace -2 - 3 - 4 "are not a sequence).
// 6. Flush(color): Five cards with same color.
// 7. Full house: three of a kind and one pair. (combination 2 and combination 3)
//8. Four of a kind: four cards with same value.
// 9. Straight Flush: Straight in which the cards have the same suite

// High card as else
// One Pair, Two Pairs
// Three of kind
// Straight - value in sequance
// Flush (heart, diamond red) (spades, clubs black)
// Full house (three kind and one pair)
// Four of kind
// Straight Flush