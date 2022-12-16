#ifndef HARBORBOARD_H_INCLUDED
#define HARBORBOARD_H_INCLUDED

#include "../Board/Board.h"
#include "Deck/Deck.h"

class HarborBoard : public Board {
private :
    Deck deck;
    size_t nb_card_dif;

public :
    virtual void initBoard();
    void fillBoard();
};


#endif // HARBORBOARD_H_INCLUDED
