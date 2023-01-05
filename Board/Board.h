#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <stack>
//#include "../Card/Establishment/Establishment.h"
#include "Enums.hpp"
#include "../Collection/Collection_standard.h"

using namespace std;

class Establishment;

class Board{
protected:
    map<EstablishmentsNames,stack<Establishment*>> cards;
    static Board* board_instance;
public :
    virtual ~Board() = default;
    Board(Board&) = default;
    void displayCards();
    void displayVector(vector<int> v);
    Establishment* foundEstablishmentOnBoard(string choice);
    // GETTERS & SETTERS
    map<EstablishmentsNames,stack<Establishment*>> getCards(){ return cards; }
    void setCards(map<EstablishmentsNames,stack<Establishment*>> establishments){  // inutile? a sup?
        cards=establishments;
    }
    static Board* getInstance(Collection_standard& g, Expansions);
    Board():cards(){}
};