#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <stack>
//#include "../Card/Establishment/Establishment.h"
#include "Enums.hpp"
using namespace std;

class Establishment;

class Board{
protected:
    map<EstablishmentsNames,stack<Establishment*>> cards;
    size_t nbCardsMax;
    static Board* board_instance;
public :
    virtual ~Board() = default;
    Board(Board&)=delete;
    virtual void displayCards();
    virtual void fillBoard();
    virtual Board& createBoard();
    Establishment* foundEstablishmentOnBoard(string choice);
    static Board* getInstance();
    // GETTERS & SETTERS
    size_t getNbCardsMax(){ return nbCardsMax; }
    map<EstablishmentsNames,stack<Establishment*>> getCards(){ return cards; }
    void setNbCardsMax(size_t nb){ nbCardsMax=nb; }
    void setCards(map<EstablishmentsNames,stack<Establishment*>> establishments){
        cards=establishments;
    }
    Board():nbCardsMax(0),cards(){}
};