#pragma once
#include "Deck/Deck.h"
#include "Board.h"
#include "../../Collection/Collection_deluxe.h"


class Deck;

class DeluxeBoard : public Board {
private :
    Deck* deck;

public:
    DeluxeBoard(Collection_deluxe&);
    void fillBoard();
    Deck* getDeck() { return deck;}
};


