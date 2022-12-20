#pragma once

//#include "Deck/Deck.h"
#include "Harbor/HarborBoard.h"
#include "../Board/GreenValleyBoard.h"

class Deck;

class DeluxeBoard : public HarborBoard, public GreenValleyBoard {

public :
    void initBoard();
};


