#pragma once
#include "../Board/Board.h"


class GreenValleyBoard : public Board {

public :
    GreenValleyBoard();
    void addEstablishmentToBoard(Establishment* e);
};


