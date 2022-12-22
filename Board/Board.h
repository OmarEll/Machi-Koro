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
    Board(Board&) = default;
    void displayCards();
    virtual void fillBoard() = 0;
    virtual Board& createBoard() = 0;
    Establishment* foundEstablishmentOnBoard(string choice);
    //static Board* getInstance(); // A REVOIR IMPERATIVEMENT ENSEMBLE (VALABLE POUR GAME AUSSI)
    // GETTERS & SETTERS
    size_t getNbCardsMax(){ return nbCardsMax; }
    map<EstablishmentsNames,stack<Establishment*>> getCards(){ return cards; }
    void setNbCardsMax(size_t nb){ nbCardsMax=nb; }
    void setCards(map<EstablishmentsNames,stack<Establishment*>> establishments){
        cards=establishments;
    }
    Board():nbCardsMax(0),cards(){}
};