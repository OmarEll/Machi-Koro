#pragma once

//#include "Deck/Deck.h"
#include "Harbor/HarborBoard.h"
#include "../../Collection/Collection_deluxe.h"


class Deck;

class DeluxeBoard : public HarborBoard {
public:
    DeluxeBoard(Collection_harbor&, Collection_deluxe&);
};


