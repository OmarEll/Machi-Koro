#pragma once
#include "Deck/Deck.h"
#include "Board.h"
#include "../Collection/Collection_harbor.h"

class HarborBoard : public Board {
private :
    Deck* deck;
    HarborBoard(Collection_harbor&){};     /////// A VOIR AVEC SARAH
public :
    friend class Board;
    void fillBoard();
    Deck* getDeck() { return deck;}
};


