#pragma once
#include "../Board/Board.h"


class GreenValleyBoard : public Board {

public :
    virtual void initBoard();
    void addEstablishmentToBoard(Establishment* e);
};


