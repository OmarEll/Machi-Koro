#pragma once

#include "Board.h"

class StandardBoard : public Board {

public :
    StandardBoard(int,map<EstablishmentsNames,stack<Establishment*>>);
    void displayCards();
    Board& createBoard();
};
