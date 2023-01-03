#pragma once
#include "Deck/Deck.h"
#include "Board.h"
#include "../../Collection/Collection_deluxe.h"


class Deck;

class DeluxeBoard : public Board {
private :
    Deck* deck;; /////// A VOIR AVEC SARAH
    DeluxeBoard(Collection_deluxe& col){};
public:
    friend class Board;
    void fillBoard();
    Deck* getDeck() { return deck;}
};


