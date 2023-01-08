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
    Board()=default;
    Board(Board&) = delete;
public :
    virtual ~Board();
    void displayCards();
    void displayVector(vector<int> v);
    Establishment* foundEstablishmentOnBoard(string choice);
    // GETTERS & SETTERS
    map<EstablishmentsNames,stack<Establishment*>> getCards(){ return cards; }
    static Board* getInstance(Collection_standard& g, Expansions);
    friend class Game;
};