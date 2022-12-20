#pragma once

#include "Board.h"

//class Board;
class Establishment;
using namespace std;

class StandardBoard : public Board {

public :
    StandardBoard(int,map<EstablishmentsNames,stack<Establishment*>>);
    ~StandardBoard();
    void displayCards();
    Board& createBoard();
};
