#pragma once

#include "Board.h"

//class Board;
class Establishment;
using namespace std;

class StandardBoard : public Board {

public :
    StandardBoard(int,map<EstablishmentsNames,stack<Establishment*>>);
    ~StandardBoard() = default;
    void displayCards() override;
    //Board& createBoard() override; A FAIRE
};
