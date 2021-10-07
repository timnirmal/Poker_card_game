//
// Created by timni on 10/4/2021.
//


#include "card.h"
#include <iostream>
#include <io.h>
#include <time.h>
#include <vector>

using namespace std;

void card::display_card() {
    _setmode(_fileno(stdout), 0x00020000);  //For print _O_U16TEXT
    //Show value first
    if((val>=2)&&(val<=10)){
        wcout<<val;
    }
    else{
        switch (val) {
            case 11: wcout<<"J"; break;
            case 12: wcout<<"Q"; break;
            case 13: wcout<<"K"; break;
            //case 14: wcout<<"A"; break;
            case 1: wcout<<"A"; break;
        }
    }

    //Printing suit
    switch (s) {
        case 0: wprintf(L"\u2663"); break;
        case 1: wprintf(L"\u2665"); break;
        case 2: wprintf(L"\u2660"); break;
        case 3: wprintf(L"\u2666"); break;
    }
}

void card::setValue(int v, suit st) {
    val = v;
    s = st;
}

int card::getValue() {
    return val;
}

suit card::getSuit() {
    return s;
}

int card::getSuitValue() {
    switch (s) {
        case 0: return 0; break;
        case 1: return 1; break;
        case 2: return 2; break;
        case 3: return 3; break;
    }
}

int card::getValueA() {
    if (val == 1){
        return 14;
    }else {
        return val;
    }

}
