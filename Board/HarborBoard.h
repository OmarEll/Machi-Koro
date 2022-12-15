#ifndef HARBORBOARD_H_INCLUDED
#define HARBORBOARD_H_INCLUDED

#include "../Board/Board.h"
#include "../Board/Deck.h"

class HarborBoard : public Board {
private :
    Deck* deck;
    size_t nb_card_dif; //?

public :
    //from super class
    void initBoard();
    void displayCards();
    void fillBoard();
    Board& createBoard();
    void initBoard();
    //new to this class
    Deck* getDeck() { return deck;}
    void reFillBoard();
};


#endif // HARBORBOARD_H_INCLUDED
