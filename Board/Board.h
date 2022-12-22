#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <stack>
//#include "../Card/Establishment/Establishment.h"
#include "Enums.hpp"
#include "../Collection/Collection.h"

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
    virtual void fillBoard() = 0;
    virtual Board& createBoard() = 0;
    Establishment* foundEstablishmentOnBoard(string choice);
    // GETTERS & SETTERS
    map<EstablishmentsNames,stack<Establishment*>> getCards(){ return cards; }
    void setCards(map<EstablishmentsNames,stack<Establishment*>> establishments){
        cards=establishments;
    }
    static Board* getInstance(Collection& g);
    Board():cards(){}
};