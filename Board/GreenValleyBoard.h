#pragma once
#include "../Board/Board.h"
#include "../Collection/Collection_GreenValley.h"

class GreenValleyBoard : public Board {
    GreenValleyBoard(Collection_GreenValley&);
public :
    friend class Board;
    void addEstablishmentToBoard(Establishment* e);
};


