#pragma once
#include "../Board/Board.h"
#include "../Collection/Collection_GreenValley.h"

class GreenValleyBoard : public Board {

public :
    GreenValleyBoard(Collection_GreenValley&);
    void addEstablishmentToBoard(Establishment* e);
};


