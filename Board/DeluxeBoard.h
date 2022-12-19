#pragma once

#include "Deck/Deck.h"
#include "Harbor/HarborBoard.h"
#include "../Board/GreenValleyBoard.h"

class DeluxeBoard : public HarborBoard, public GreenValleyBoard {

public :
    void initBoard();
};


