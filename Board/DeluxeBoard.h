#ifndef DELUXEBOARD_H_INCLUDED
#define DELUXEBOARD_H_INCLUDED

#include "Deck/Deck.h"
#include "../Board/HarborBoard.h"
#include "../Board/GreenValleyBoard.h"

class DeluxeBoard : public HarborBoard, public GreenValleyBoard {

public :
    void initBoard();
};

#endif // DELUXEBOARD_H_INCLUDED
