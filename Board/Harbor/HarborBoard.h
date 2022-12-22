#pragma once
/*#include "../Board/Board.h"
#include "Deck/Deck.h"*/
#include "Board.h"
#include "../Collection/Collection_harbor.h"

class Deck;
class Board;

class HarborBoard : public Board {
private :
    Deck* deck;

public :
    HarborBoard(Collection_harbor& col);
    void fillBoard();
    Deck* getDeck() { return deck;}
};


