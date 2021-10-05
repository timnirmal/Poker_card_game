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

int player::score() {
    vector<card> hand_Copy;

    //for (int i=0; i< 5; i++){
      //  hand_Copy[i] = hand [i];
    //}

// enum suit {clubs, heart, spades, diamond};
// ♣0 ♥1 ♠2 ♦3

    //Taking values and suites to two arrays
    hand[0].getValue();
    hand[0].getSuit();


    wcout<<endl<<"Card = ";
    for (int i=0; i<5; i++) {
        hand[i].display_card();
        wcout<<" ";
    }

    int arrVal[15];
    int arrSuit[4];


    for (int i=0; i<4; i++) {
        arrSuit[i] = 0;
    }

    for (int i=0; i<15; i++) {
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
            case 1: arrVal[1]++; arrVal[14]++; break;
            case 2: arrVal[2]++; break;
            case 3: arrVal[3]++; break;
            case 4: arrVal[4]++; break;
            case 5: arrVal[5]++; break;
            case 6: arrVal[6]++; break;
            case 7: arrVal[7]++; break;
            case 8: arrVal[8]++; break;
            case 9: arrVal[9]++; break;
            case 10: arrVal[10]++; break;
            case 11: arrVal[11]++; break;
            case 12: arrVal[12]++; break;
            case 13: arrVal[13]++; break;
        }
    }

    wcout << endl;

    for (int i=0; i<4; i++) {
        wcout << arrSuit[i] << " ";
    }
    wcout << endl;
    for (int i=1; i<15; i++) {
        wcout << arrVal[i] << " ";
    }

    int highCard, onePair, twoPair, threeKind, straight, flush, fullHouse, fourKind, straightFlush;
    highCard = onePair = twoPair = threeKind = straight = flush = fullHouse = fourKind = straightFlush = 0;
    //Straight Flush - All have same suite

    for (int i=0; i<4; i++) {
        if ( arrSuit[i] == 5){
            //straightFlush = 1;
            return 9;
        }
        else if ((arrSuit[0] + arrSuit[2]) == 5 || (arrSuit[1] + arrSuit[3]) == 5 ){
            //flush = 1;
            return 6;
        }
    }

    for (int i=0; i<14; i++) {
        if ( arrVal[i] == 4){
            //fourKind = 1;
            return 8;
        }
        else if ( arrVal[i] == 3){
            threeKind = 1;
        }
        else if ( arrVal[i] == 2){
            onePair++;
        }
    }

    for (int i=1; i<11; i++) {
       if ( (arrVal[i] == 1) && (arrVal[i+1] == 1) && (arrVal[i+2] == 1) && (arrVal[i+3] == 1) && (arrVal[i+4] == 1)){
            //straight = 1;
           return 5;
        }
    }

    if (threeKind == 1 && onePair == 1){
        return 7;
    }
    else if (threeKind == 1) {
        return 4;
    }
    else if (onePair == 2) {
        return 3;
    }
    else if (onePair == 1) {
        return 2;
    }
    else {
        return 0;
    }
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