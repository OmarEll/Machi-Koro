#ifndef STANDARDBOARD_H_INCLUDED
#define STANDARDBOARD_H_INCLUDED
#include "Board.h"

class StandardBoard : public Board {

public :
    StandardBoard(int,map<EstablishmentsNames,stack<Establishment*>>);
    void displayCards();
    Board& createBoard();
};

#endif // STANDARDBOARD_H_INCLUDED